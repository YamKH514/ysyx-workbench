#!/usr/bin/env python3
"""
Cache Simulation Parallel Testing Script
Runs multiple Cache simulation tests with different M, N parameters using 4 threads.
"""

import subprocess
import sys
import os
from concurrent.futures import ThreadPoolExecutor, as_completed
from dataclasses import dataclass
from typing import List, Tuple
import re

@dataclass
class CacheConfig:
    M: int
    N: int
    block_size: int  # 2^M bytes
    num_lines: int   # 2^N
    total_size: int  # block_size * num_lines in KB
    
    def __str__(self):
        return f"M={self.M},N={self.N} ({self.total_size}KB)"

@dataclass
class TestResult:
    config: CacheConfig
    total_accesses: int
    cache_hits: int
    cache_misses: int
    hit_rate: float
    miss_time: float
    success: bool
    error_msg: str = None
    
    def __str__(self):
        if not self.success:
            return f"M={self.config.M:2d} N={self.config.N:2d} - ERROR: {self.error_msg}"
        return (f"M={self.config.M:2d} N={self.config.N:2d} ({self.config.total_size:5d}KB) | "
                f"Hits: {self.cache_hits:8d} | Misses: {self.cache_misses:8d} | "
                f"Hit Rate: {self.hit_rate:6.2f}% | Miss Time: {self.miss_time:10.2f}")

def generate_configs(m_range: Tuple[int, int], n_range: Tuple[int, int]) -> List[CacheConfig]:
    """
    Generate cache configurations for testing.
    Args:
        m_range: (min_m, max_m) tuple
        n_range: (min_n, max_n) tuple
    Returns:
        List of CacheConfig objects
    """
    configs = []
    for m in range(m_range[0], m_range[1] + 1):
        for n in range(n_range[0], n_range[1] + 1):
            block_size = 1 << m  # 2^m
            num_lines = 1 << n   # 2^n
            total_size = (block_size * num_lines) // 1024  # Convert to KB
            configs.append(CacheConfig(m, n, block_size, num_lines, total_size))
    return configs

def run_single_test(config: CacheConfig, binary_path: str = "./cachesim") -> TestResult:
    """
    Run a single cache simulation test.
    Args:
        config: CacheConfig object
        binary_path: Path to the cachesim binary
    Returns:
        TestResult object
    """
    try:
        # Build command
        cmd = [binary_path, str(config.M), str(config.N)]
        
        # Check if binary exists
        if not os.path.exists(binary_path):
            return TestResult(
                config=config,
                total_accesses=0,
                cache_hits=0,
                cache_misses=0,
                hit_rate=0,
                miss_time=0,
                success=False,
                error_msg=f"Binary not found: {binary_path}"
            )
        
        # Run the command
        result = subprocess.run(
            cmd,
            capture_output=True,
            text=True,
            timeout=60
        )
        
        if result.returncode != 0:
            return TestResult(
                config=config,
                total_accesses=0,
                cache_hits=0,
                cache_misses=0,
                hit_rate=0,
                miss_time=0,
                success=False,
                error_msg=f"Exit code: {result.returncode}\n{result.stderr}"
            )
        
        # Parse output
        stdout = result.stdout
        
        # Extract results using regex
        total_match = re.search(r'Total accesses:\s*(\d+)', stdout)
        hits_match = re.search(r'Cache hits:\s*(\d+)', stdout)
        misses_match = re.search(r'Cache misses:\s*(\d+)', stdout)
        rate_match = re.search(r'ICache Hit rate:\s*([\d.]+)%', stdout)
        time_match = re.search(r'Total Miss Time:\s*([\d.]+)', stdout)
        
        if not all([total_match, hits_match, misses_match, rate_match, time_match]):
            return TestResult(
                config=config,
                total_accesses=0,
                cache_hits=0,
                cache_misses=0,
                hit_rate=0,
                miss_time=0,
                success=False,
                error_msg="Failed to parse output"
            )
        
        total_accesses = int(total_match.group(1))
        cache_hits = int(hits_match.group(1))
        cache_misses = int(misses_match.group(1))
        hit_rate = float(rate_match.group(1))
        miss_time = float(time_match.group(1))
        
        return TestResult(
            config=config,
            total_accesses=total_accesses,
            cache_hits=cache_hits,
            cache_misses=cache_misses,
            hit_rate=hit_rate,
            miss_time=miss_time,
            success=True
        )
        
    except subprocess.TimeoutExpired:
        return TestResult(
            config=config,
            total_accesses=0,
            cache_hits=0,
            cache_misses=0,
            hit_rate=0,
            miss_time=0,
            success=False,
            error_msg="Timeout (60s exceeded)"
        )
    except Exception as e:
        return TestResult(
            config=config,
            total_accesses=0,
            cache_hits=0,
            cache_misses=0,
            hit_rate=0,
            miss_time=0,
            success=False,
            error_msg=str(e)
        )

def run_parallel_tests(configs: List[CacheConfig], num_workers: int = 4, 
                      binary_path: str = "./cachesim") -> List[TestResult]:
    """
    Run multiple cache tests in parallel using thread pool.
    Args:
        configs: List of CacheConfig objects
        num_workers: Number of worker threads
        binary_path: Path to the cachesim binary
    Returns:
        List of TestResult objects
    """
    results = []
    
    print(f"Starting parallel tests with {num_workers} worker threads...")
    print(f"Total configurations to test: {len(configs)}")
    print("=" * 100)
    
    with ThreadPoolExecutor(max_workers=num_workers) as executor:
        # Submit all tasks
        future_to_config = {
            executor.submit(run_single_test, config, binary_path): config 
            for config in configs
        }
        
        # Process completed tasks
        completed = 0
        for future in as_completed(future_to_config):
            result = future.result()
            results.append(result)
            completed += 1
            
            # Print progress
            status = "✓" if result.success else "✗"
            print(f"[{completed}/{len(configs)}] {status} {result}")
    
    return results

def print_summary(results: List[TestResult]):
    """Print summary statistics."""
    successful = [r for r in results if r.success]
    failed = [r for r in results if not r.success]
    
    print("\n" + "=" * 100)
    print("SUMMARY")
    print("=" * 100)
    print(f"Total tests: {len(results)}")
    print(f"Successful: {len(successful)}")
    print(f"Failed: {len(failed)}")
    
    if successful:
        print("\n" + "-" * 100)
        print("Statistics of successful tests:")
        print("-" * 100)
        
        avg_hit_rate = sum(r.hit_rate for r in successful) / len(successful)
        max_hit_rate = max(successful, key=lambda r: r.hit_rate)
        min_hit_rate = min(successful, key=lambda r: r.hit_rate)
        
        print(f"Average Hit Rate: {avg_hit_rate:.2f}%")
        print(f"Max Hit Rate: {max_hit_rate.hit_rate:.2f}% (Config: {max_hit_rate.config})")
        print(f"Min Hit Rate: {min_hit_rate.hit_rate:.2f}% (Config: {min_hit_rate.config})")
        
        # Find best and worst miss times
        best_miss_time = min(successful, key=lambda r: r.miss_time)
        worst_miss_time = max(successful, key=lambda r: r.miss_time)
        
        print(f"Best Miss Time: {best_miss_time.miss_time:.2f} (Config: {best_miss_time.config})")
        print(f"Worst Miss Time: {worst_miss_time.miss_time:.2f} (Config: {worst_miss_time.config})")
    
    if failed:
        print("\n" + "-" * 100)
        print("Failed tests:")
        print("-" * 100)
        for result in failed:
            print(f"  {result}")

def main():
    """Main entry point."""
    # Check if binary exists
    if not os.path.exists("./cachesim"):
        print("Error: cachesim binary not found. Please build first with: make all")
        sys.exit(1)
    
    # Define test configurations
    # (M, N) pairs: M is block size bits (2^M bytes), N is number of lines bits (2^N lines)
    # This tests combinations from 64B (M=6) to 4KB (M=12) cache lines
    # and 1 line (N=0) to 4096 lines (N=12)
    
    configs = generate_configs(m_range=(2, 6), n_range=(4, 11))
    
    print(f"Generated {len(configs)} test configurations:")
    for i, config in enumerate(configs, 1):
        print(f"  {i:2d}. {config}")
    print()
    
    # Run parallel tests with 4 workers
    results = run_parallel_tests(configs, num_workers=4)
    
    # Print summary
    print_summary(results)
    
    # Export results to CSV
    csv_path = "cache_test_results.csv"
    with open(csv_path, 'w') as f:
        f.write("M,N,BlockSize,NumLines,TotalSizeKB,TotalAccesses,CacheHits,CacheMisses,HitRate(%),MissTime\n")
        for result in results:
            if result.success:
                f.write(f"{result.config.M},{result.config.N},{result.config.block_size},"
                       f"{result.config.num_lines},{result.config.total_size},"
                       f"{result.total_accesses},{result.cache_hits},{result.cache_misses},"
                       f"{result.hit_rate:.2f},{result.miss_time:.2f}\n")
    
    print(f"\nResults exported to: {csv_path}")

if __name__ == "__main__":
    main()
