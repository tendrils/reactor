NAME=rfa-core
CONF=debug-semihost
BOARD=same70-xpld

BASE=../..

CONF_PATH=${CONF}/${BOARD}
CONF_DIR=conf/${CONF_PATH}
OBJECTDIR=obj/${CONF_PATH}
DISTDIR=dist/${CONF_PATH}

STARTUP_DEFS=-D__NO_SYSTEM_INIT

CXXFLAGS+=-D__STARTUP_COPY_MULTIPLE -D__STARTUP_CLEAR_BSS_MULTIPLE


OBJECTFILES=rfa_core.o 

include vars.mk

LDSCRIPTS=-L. -L$(BASE)/ldscripts -T gcc.ld
LFLAGS=$(USE_NANO) $(USE_SEMIHOST) $(LDSCRIPTS) $(GC) $(MAP)

# build
build: .build-post

.build-pre:
# Add your pre 'build' code here...

.build-post: .build-impl
# Add your post 'build' code here...


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
${DISTDIR}/${CONF}/${PLATFORM}/lib${NAME}-${CORE}.a: ${OBJECTFILES}
	${MKDIR} -p ${DISTDIR}/${CONF}/${XC_TARGET}
	${LD} -o $@ ${OBJECTFILES} ${LFLAGS}

${OBJECTDIR}/rfa_core.o:
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	${CC} -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/rfa_core.o rfa_core.c

#
# build step implementations
#
.build-impl: ${DISTDIR}/lib${NAME}-${CORE}.a
	
.clean-impl:
	
.clobber-impl:

.all-impl: clean build test

.build-tests-impl:
	
.test-impl:
	
.help-impl: