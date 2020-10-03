.PHONY: clean
.PHONY: test
.PHONY: format
.PHONY: lint
.PHONY: check

install:
	pip install .

docs:
	 cd docs && make html

build:
	mkdir build && cd build && cmake -DCMAKE_BUILD_TYPE=Release .. && make

debug:
	mkdir build && cd build && cmake -DCMAKE_BUILD_TYPE=Debug .. && make

clean:
	rm -rf build

test: clean debug
	cd build && ctest -j4
	pytest -v --doctest-modules --ignore example/pybind11 example tests

format:
	black --exclude example/pybind11/ example tests
	clang-format -i example/include/*hpp
	clang-format -i example/src/*cpp
	clang-format -i tests/*cpp

lint:
	cpplint --filter=-legal/copyright,-readability/casting,-whitespace/comments \
	  example/src/*.cpp example/include/*.hpp tests/*cpp
	pylint example

check:
	cppcheck example/src/*.cpp example/include/*.hpp tests/*cpp
