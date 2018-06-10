modules=$(shell find ./module -mindepth 1 -maxdepth 1 -type d)
testmodules=$(shell find ./test-module -mindepth 1 -maxdepth 1 -type d)
all:
	echo "Building modules..."
	for d in $(modules); do make -C $$d || exit 1; done
	for d in $(testmodules); do make -C $$d || exit 1; done

clean:
	echo "Building test modules..."
	for d in $(modules); do make -C $$d $@; done
	for d in $(modules); do make -C $$d $@; done
