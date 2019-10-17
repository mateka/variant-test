# Variant tests

Testing speed of static OO vs classic OO.

# Results
## Ubuntu 18.04 Intel(R) Core(TM) i5-5200U CPU (2 cores, 4 threads, 2.20GHz) 8GB RAM
|Objects | Repetitions | Calls| OO | Variant | Ratio [variant / oo] |
|---------------:|---------------:|---------------:|---------------:|---------------:|---------------:|
|          10 |   10000000 |  100000000 |     1.4062 |    1.57696 |    1.12144 |
|         100 |    1000000 |  100000000 |    1.07896 |    1.17743 |    1.09126 |
|        1000 |     100000 |  100000000 |     1.0301 |    1.13055 |    1.09751 |
|     1000000 |        100 |  100000000 |    1.27242 |    1.18896 |    0.93441 |
|   100000000 |          1 |  100000000 |     1.2696 |    1.08642 |   0.855722 |
|   150000000 |          1 |  150000000 |    1.94392 |    1.66738 |    0.85774 |
|   200000000 |          1 |  200000000 |    273.482 |    2.11073 |   0.007718 |
|   250000000 |          1 |  250000000 |    292.634 |    2.83409 | 0.00968478 |