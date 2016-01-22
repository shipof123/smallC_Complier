rm testcase-output/*;
make clean;
make;
./scc tests/arth.sc  			  testout/arth.ll
./scc tests/fib.sc  			  testout/fib.ll
./scc tests/gcd.sc                 	  testout/gcd.ll
./scc tests/io.sc          		  testout/io.ll
./scc tests/if.sc                         testout/if.ll
./scc tests/queen.sc             	  testout/queen.ll
./scc tests/struct.sc           	  testout/struct.ll
make clean;
