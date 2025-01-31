# Introduction to Algorithms
<sub>From MIT, 6.006, Spring 2020</sub>\
<sub>Goals: Solve Computational problems, Prove Correctness, argue efficiency, Communication</sub>

## Algorithms and Computation

### Efficiency
**Asymptotic Notation:** ignore constant factors and low order terms
– Upper bounds (O), lower bounds (Ω), tight bounds (Θ) ∈, =, is, order
– Time estimate below based on one operation per cycle on a 1 GHz single-core machine
– Particles in universe estimated < $10^{100}$
input | constant | logarithmic | linear | log-linear | quadratic | polynomial  | exponential
-|-|-|-|-|-|-|-
n | Θ(1) | Θ(log n)| Θ(n)| Θ(n log n)| Θ($n^2$)| Θ($n^c$)| $2^{Θ(n^c)}$
1000 | 1 | ≈ 10 | 1000 | ≈ 10,000 | 1,000,000| $1000^c$| $2^{1000} ≈ 10^{301}$
Time | 1 ns | 10 ns | 1 µs | 10 µs | 1 ms | $10^{3c−9} s | $10^{281} millenia


## MATH

$(1+2+4+8+16+32+...n)=\sum_{i=0}^n 2^i = 2^n - 1$