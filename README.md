# PHILOSOPHERS - Dining Philosophers Problem
A 42 Common Core project that simulates the classic Dining Philosophers synchronization problem using threads and mutexes.

## Overview
The Philosophers project tackles one of the most famous problems in computer science - the Dining Philosophers Problem. This simulation demonstrates concurrent programming concepts, thread synchronization, and deadlock prevention using POSIX threads and mutexes.

The program simulates philosophers sitting around a circular table, each needing two forks to eat. The challenge is to prevent deadlocks, race conditions, and ensure no philosopher starves.

## Quick Start

### Installation
```bash
git clone https://github.com/BeAzarym/42-PHILOSOPHERS.git
cd 42-PHILOSOPHERS
make
```

### Basic Usage
```bash
./philo number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]
```

### Example Usage
```bash
./philo 5 800 200 200          # 5 philosophers, basic simulation
./philo 5 800 200 200 7        # Each philosopher must eat 7 times
./philo 4 410 200 200          # Edge case: should not die
./philo 1 800 200 200          # Single philosopher (should die)
```

## Parameters

| Parameter | Description | Required |
|-----------|-------------|----------|
| `number_of_philosophers` | Number of philosophers (and forks) | Yes |
| `time_to_die` | Time in ms before a philosopher dies from starvation | Yes |
| `time_to_eat` | Time in ms a philosopher takes to eat | Yes |
| `time_to_sleep` | Time in ms a philosopher spends sleeping | Yes |
| `number_of_times_each_philosopher_must_eat` | Simulation ends when all philosophers have eaten this many times | No |

## Program Output

The program outputs timestamped messages for each philosopher action:
```
[timestamp_ms] [philosopher_id] has taken a fork
[timestamp_ms] [philosopher_id] is eating
[timestamp_ms] [philosopher_id] is sleeping  
[timestamp_ms] [philosopher_id] is thinking
[timestamp_ms] [philosopher_id] died
```

### Example Output
```
0 1 has taken a fork
0 1 has taken a fork
0 1 is eating
0 3 has taken a fork
0 3 has taken a fork
0 3 is eating
200 1 is sleeping
200 3 is sleeping
200 2 has taken a fork
200 2 has taken a fork
200 2 is eating
```

## Testing

### Basic Tests
```bash
# Test with different philosopher counts
./philo 2 410 200 200      # Minimum case
./philo 5 800 200 200      # Standard case
./philo 10 800 200 200     # Larger simulation

# Test edge cases
./philo 1 800 200 200      # Single philosopher (should die)
./philo 4 310 200 100      # Tight timing (should die)
./philo 4 410 200 100      # Should survive
```

### Performance Tests
```bash
# Test with many philosophers
./philo 100 800 200 200    # Stress test
./philo 200 800 200 200    # Heavy load test

# Test with eating limits
./philo 5 800 200 200 10   # Each must eat 10 times
./philo 4 410 200 200 10   # Tight timing with eating limit
```

### Death Timing Tests
```bash
./philo 1 800 200 200      # Should die at ~800ms
./philo 4 310 200 100      # Should die (not enough time)
./philo 2 800 300 100      # Should not die
```

## Project Structure
```
philo/
├── src/                   # Source files
│   ├── main.c            # Program entry point
│   ├── parser.c          # Argument parsing and validation
│   ├── init.c            # Initialization functions
│   ├── eat.c             # Eating logic and fork management
│   ├── print.c           # Thread-safe printing
│   ├── utils.c           # Utility functions (time, sleep)
│   ├── end_condition.c   # Death and completion checking
│   └── error.c           # Error handling and cleanup
├── include/              # Header files
│   └── philosophers.h    # Main header with structures and prototypes
├── Makefile              # Build configuration
└── README.md
```

## Technical Implementation

### Key Concepts Implemented
- **Thread Management**: Each philosopher runs in its own thread
- **Mutex Synchronization**: Forks are protected by mutexes to prevent race conditions
- **Deadlock Prevention**: Careful ordering of fork acquisition prevents circular wait
- **Precise Timing**: Accurate millisecond timing for all operations
- **Thread-Safe Output**: Mutex-protected printing to prevent garbled output

### Data Structures
```c
typedef struct s_philosophers {
    int                 pos;           // Philosopher position
    int                 lfork_id;      // Left fork ID
    int                 rfork_id;      // Right fork ID
    uint64_t           last_meal;      // Timestamp of last meal
    pthread_t          id;             // Thread ID
    struct s_settings  *settings;     // Shared settings
} t_philosophers;

typedef struct s_settings {
    int                 nb_philo;      // Number of philosophers
    uint64_t           time_to_eat;    // Time to eat in ms
    uint64_t           time_to_sleep;  // Time to sleep in ms
    uint64_t           time_to_die;    // Time to die in ms
    int                limits;         // Required meals (-1 if unlimited)
    time_t             start;          // Simulation start time
    pthread_mutex_t    talking;        // Print protection mutex
    pthread_mutex_t    *forks;         // Fork mutexes array
    t_philosophers     *philosophers;  // Philosophers array
} t_settings;
```

### Synchronization Strategy
1. **Fork Assignment**: Each philosopher has a left and right fork
2. **Acquisition Order**: Lower-numbered fork acquired first to prevent deadlock
3. **State Tracking**: Last meal time tracked for death detection
4. **Atomic Operations**: Thread-safe access to shared resources

## Build Commands
```bash
make        # Compile project
make clean  # Remove object files
make fclean # Remove all generated files
make re     # Full rebuild
```

## Rules and Constraints
- Each philosopher needs 2 forks to eat
- Forks are placed between philosophers (shared resource)
- Philosophers alternate between eating, sleeping, and thinking
- Simulation stops when a philosopher dies or all have eaten enough times
- No philosopher should die if the timing allows survival
- Output must be clean and properly timestamped

## Common Edge Cases
- **Single Philosopher**: Should die (only one fork available)
- **Two Philosophers**: Can work with proper synchronization
- **Tight Timing**: When `time_to_die` ≈ `time_to_eat + time_to_sleep`
- **Many Philosophers**: System resource management becomes critical

## Error Handling
The program handles various error conditions:
- Invalid number of arguments
- Non-numeric arguments
- Negative numbers
- Memory allocation failures
- Mutex initialization failures

---