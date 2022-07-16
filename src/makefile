


checks:
	make cppLint
	make cppCheck

cppLint: 
	python3 ../materials/linters/cpplint.py --extensions=c *.c *.h

cppCheck:
	cppcheck --enable=all --suppress=missingIncludeSystem *.c

leaks:
	leaks -atExit -- ../build/./polish_notation

remove_cpplint: CPPLINT.cfg
	rm CPPLINT.cfg