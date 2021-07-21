# Push_swap_42cursus (42cursus)

- 1 ./push_swap 1 3 2

- 2 ARG="4 67 3 87 23"; ./push_swap $ARG | wc -l

- 3 ARG=$(seq 0 1000 | sort -R | tail -n 100 | tr '\n' ' ') ; ./push_swap $ARG | wc -l

- 4 ARG=$(seq -1000 1000 | sort -R | tail -n 500 | tr '\n' ' ') ; ./push_swap $ARG | ./checker $ARG
