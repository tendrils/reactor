default: build

NAME=rfa-core

include ../../common.mk

OBJECTFILES+=\
    ${OBJECTDIR}/rfa_core.o\
    ${OBJECTDIR}/kernel.o\
    ${OBJECTDIR}/port/port_kernel_freertos.o\
    #${OBJECTDIR}/startup.o

# build
build: .build-post

.build-pre:

.build-post: .build-impl

# clean
clean: .clean-post

.clean-pre:
# Add your pre 'clean' code here...

.clean-post: .clean-impl
# Add your post 'clean' code here...


# clobber
clobber: .clobber-post

.clobber-pre:
# Add your pre 'clobber' code here...

.clobber-post: .clobber-impl
# Add your post 'clobber' code here...


# all
all: .all-post

.all-pre:
# Add your pre 'all' code here...

.all-post: .all-impl
# Add your post 'all' code here...


# build tests
build-tests: .build-tests-post

.build-tests-pre:
# Add your pre 'build-tests' code here...

.build-tests-post: .build-tests-impl
# Add your post 'build-tests' code here...

# run tests
test: .test-post

.test-pre: build-tests
# Add your pre 'test' code here...

.test-post: .test-impl
# Add your post 'test' code here...


# help
help: .help-post

.help-pre:
# Add your pre 'help' code here...

.help-post: .help-impl
# Add your post 'help' code here...

# Build Targets
${DISTDIR}/lib${NAME}-${CPU_ARCH}.a: ${OBJECTFILES}
	${MKDIR} -p ${DISTDIR}
	${LD} -o $@ ${OBJECTFILES} ${LFLAGS}

${OBJECTDIR}/rfa_core.o: src/rfa_core.c
	${CC} $(CFLAGS) -o $@ $^

${OBJECTDIR}/kernel.o: src/kernel.c
	${CC} $(CFLAGS) -o $@ $^
	
${OBJECTDIR}/port/port_kernel_freertos.o: src/port/port_kernel_freertos.c
	${CC} $(CFLAGS) -o $@ $^
#
# build step implementations
#
.build-impl: ${DISTDIR}/lib${NAME}-${CPU_ARCH}.a
	
.clean-impl:
	
.clobber-impl:

.all-impl: clean build test

.build-tests-impl:
	
.test-impl:
	
.help-impl: