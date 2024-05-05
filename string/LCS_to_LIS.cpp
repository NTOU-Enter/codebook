(1) LCS problem:

index: 0 1 2 3 4 5 6
--------------------
s1:    a b a c d
s2:    d b a a b c a

(2)matched positions:

  a     a     a     b     b 
(0,2) (0,3) (0,6) (1,1) (1,4)
  a     a     a     c     d
(2,2) (2,3) (2,6) (3,5) (4,0)

(3)sort all pairs:

increasing in 1st components.
decreasing in 2nd components if ties.

(4) 1D LIS:

use 2nd components to LIS