#!/bin/bash

{
    echo "======= Test begin! ======="
    echo "******error1******"
    ./bin/p ./test_file/error1
    echo "******error3******"
    ./bin/p ./test_file/error3
    echo "******error5******"
    ./bin/p ./test_file/error5
    echo "******error6******"
    ./bin/p ./test_file/error6
    echo "******error7******"
    ./bin/p ./test_file/error7
    echo "******error10******"
    ./bin/p ./test_file/error10
    echo "******error12******"
    ./bin/p ./test_file/error12
} | tee test_result.log
echo "======= Test finished at $(date) =======" >> test_result.log
