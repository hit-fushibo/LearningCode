#!/bin/bash

{
    echo "======= Test begin! ======="
    echo "******typr A error******"
    ./bin/parser ./test_file/A_type_error
    echo "******typr B error******"
    ./bin/parser ./test_file/B_type_error
    echo "******  correct   ******"
    ./bin/parser ./test_file/correct
} | tee test_result.log
echo "======= Test finished at $(date) =======" >> test_result.log
