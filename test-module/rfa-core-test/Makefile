CONF=debug

# Environment 
MKDIR=mkdir
CP=cp
RM=rm
CCADMIN=CCadmin

PLATFORM=arm-none-eabi

XC_PREFIX=${PLATFORM}-

CC=${XC_PREFIX}gcc
CXX=${XC_PREFIX}g++
AS=${XC_PREFIX}as
LD=${XC_PREFIX}ld

OBJECTDIR=obj
DISTDIR=dist

OBJECTFILES=${OBJECTDIR}/main.o

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
${DISTDIR}/${CONF}/${PLATFORM}/reactor-core.a: ${OBJECTFILES}
	${MKDIR} -p ${DISTDIR}/${CONF}/${XC_TARGET}
	${LD} -o ${DISTDIR}/${CONF}/${PLATFORM}/reactor-core.a ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/main.o:
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	${CC} -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/main.o main.c

#
# build step implementations
#
.build-impl: ${DISTDIR}/${CONF}/${PLATFORM}/reactor-core.a
	
.clean-impl:
	
.clobber-impl:

.all-impl: clean build test help

.build-tests-impl:
	
.test-impl:
	
.help-impl: