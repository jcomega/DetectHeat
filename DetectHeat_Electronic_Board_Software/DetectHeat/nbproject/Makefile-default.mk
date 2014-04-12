#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Include project Makefile
ifeq "${IGNORE_LOCAL}" "TRUE"
# do not include local makefile. User is passing all local related variables already
else
include Makefile
# Include makefile containing local settings
ifeq "$(wildcard nbproject/Makefile-local-default.mk)" "nbproject/Makefile-local-default.mk"
include nbproject/Makefile-local-default.mk
endif
endif

# Environment
MKDIR=gnumkdir -p
RM=rm -f 
MV=mv 
CP=cp 

# Macros
CND_CONF=default
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
IMAGE_TYPE=debug
OUTPUT_SUFFIX=cof
DEBUGGABLE_SUFFIX=cof
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/DetectHeat.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=cof
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/DetectHeat.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Source Files Quoted if spaced
SOURCEFILES_QUOTED_IF_SPACED=Sources/BlueCom.c Sources/Interrupts.c Sources/main.c Sources/UARTIntC.c Sources/tick.c Sources/RTTTLtone.c Sources/Gest_Energy.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/Sources/BlueCom.o ${OBJECTDIR}/Sources/Interrupts.o ${OBJECTDIR}/Sources/main.o ${OBJECTDIR}/Sources/UARTIntC.o ${OBJECTDIR}/Sources/tick.o ${OBJECTDIR}/Sources/RTTTLtone.o ${OBJECTDIR}/Sources/Gest_Energy.o
POSSIBLE_DEPFILES=${OBJECTDIR}/Sources/BlueCom.o.d ${OBJECTDIR}/Sources/Interrupts.o.d ${OBJECTDIR}/Sources/main.o.d ${OBJECTDIR}/Sources/UARTIntC.o.d ${OBJECTDIR}/Sources/tick.o.d ${OBJECTDIR}/Sources/RTTTLtone.o.d ${OBJECTDIR}/Sources/Gest_Energy.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/Sources/BlueCom.o ${OBJECTDIR}/Sources/Interrupts.o ${OBJECTDIR}/Sources/main.o ${OBJECTDIR}/Sources/UARTIntC.o ${OBJECTDIR}/Sources/tick.o ${OBJECTDIR}/Sources/RTTTLtone.o ${OBJECTDIR}/Sources/Gest_Energy.o

# Source Files
SOURCEFILES=Sources/BlueCom.c Sources/Interrupts.c Sources/main.c Sources/UARTIntC.c Sources/tick.c Sources/RTTTLtone.c Sources/Gest_Energy.c


CFLAGS=
ASFLAGS=
LDLIBSOPTIONS=

############# Tool locations ##########################################
# If you copy a project from one host to another, the path where the  #
# compiler is installed may be different.                             #
# If you open this project with MPLAB X in the new host, this         #
# makefile will be regenerated and the paths will be corrected.       #
#######################################################################
# fixDeps replaces a bunch of sed/cat/printf statements that slow down the build
FIXDEPS=fixDeps

# The following macros may be used in the pre and post step lines
Device=PIC18LF14K22
ProjectDir="D:\CloudStation\Projets_JC\DetectHeat\DetectHeat_Electronic_Board_Software\DetectHeat"
ConfName=default
ImagePath="dist\default\${IMAGE_TYPE}\DetectHeat.${IMAGE_TYPE}.${OUTPUT_SUFFIX}"
ImageDir="dist\default\${IMAGE_TYPE}"
ImageName="DetectHeat.${IMAGE_TYPE}.${OUTPUT_SUFFIX}"

.build-conf:  .pre ${BUILD_SUBPROJECTS}
	${MAKE} ${MAKE_OPTIONS} -f nbproject/Makefile-default.mk dist/${CND_CONF}/${IMAGE_TYPE}/DetectHeat.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
	@echo "--------------------------------------"
	@echo "User defined post-build step: []"
	@
	@echo "--------------------------------------"

MP_PROCESSOR_OPTION=18LF14K22
MP_PROCESSOR_OPTION_LD=18lf14k22
MP_LINKER_DEBUG_OPTION= -u_DEBUGCODESTART=0x3e00 -u_DEBUGCODELEN=0x200
# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/Sources/BlueCom.o: Sources/BlueCom.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/Sources 
	@${RM} ${OBJECTDIR}/Sources/BlueCom.o.d 
	@${RM} ${OBJECTDIR}/Sources/BlueCom.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -p$(MP_PROCESSOR_OPTION) -I".." -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/Sources/BlueCom.o   Sources/BlueCom.c 
	@${DEP_GEN} -d ${OBJECTDIR}/Sources/BlueCom.o 
	@${FIXDEPS} "${OBJECTDIR}/Sources/BlueCom.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/Sources/Interrupts.o: Sources/Interrupts.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/Sources 
	@${RM} ${OBJECTDIR}/Sources/Interrupts.o.d 
	@${RM} ${OBJECTDIR}/Sources/Interrupts.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -p$(MP_PROCESSOR_OPTION) -I".." -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/Sources/Interrupts.o   Sources/Interrupts.c 
	@${DEP_GEN} -d ${OBJECTDIR}/Sources/Interrupts.o 
	@${FIXDEPS} "${OBJECTDIR}/Sources/Interrupts.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/Sources/main.o: Sources/main.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/Sources 
	@${RM} ${OBJECTDIR}/Sources/main.o.d 
	@${RM} ${OBJECTDIR}/Sources/main.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -p$(MP_PROCESSOR_OPTION) -I".." -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/Sources/main.o   Sources/main.c 
	@${DEP_GEN} -d ${OBJECTDIR}/Sources/main.o 
	@${FIXDEPS} "${OBJECTDIR}/Sources/main.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/Sources/UARTIntC.o: Sources/UARTIntC.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/Sources 
	@${RM} ${OBJECTDIR}/Sources/UARTIntC.o.d 
	@${RM} ${OBJECTDIR}/Sources/UARTIntC.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -p$(MP_PROCESSOR_OPTION) -I".." -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/Sources/UARTIntC.o   Sources/UARTIntC.c 
	@${DEP_GEN} -d ${OBJECTDIR}/Sources/UARTIntC.o 
	@${FIXDEPS} "${OBJECTDIR}/Sources/UARTIntC.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/Sources/tick.o: Sources/tick.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/Sources 
	@${RM} ${OBJECTDIR}/Sources/tick.o.d 
	@${RM} ${OBJECTDIR}/Sources/tick.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -p$(MP_PROCESSOR_OPTION) -I".." -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/Sources/tick.o   Sources/tick.c 
	@${DEP_GEN} -d ${OBJECTDIR}/Sources/tick.o 
	@${FIXDEPS} "${OBJECTDIR}/Sources/tick.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/Sources/RTTTLtone.o: Sources/RTTTLtone.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/Sources 
	@${RM} ${OBJECTDIR}/Sources/RTTTLtone.o.d 
	@${RM} ${OBJECTDIR}/Sources/RTTTLtone.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -p$(MP_PROCESSOR_OPTION) -I".." -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/Sources/RTTTLtone.o   Sources/RTTTLtone.c 
	@${DEP_GEN} -d ${OBJECTDIR}/Sources/RTTTLtone.o 
	@${FIXDEPS} "${OBJECTDIR}/Sources/RTTTLtone.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/Sources/Gest_Energy.o: Sources/Gest_Energy.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/Sources 
	@${RM} ${OBJECTDIR}/Sources/Gest_Energy.o.d 
	@${RM} ${OBJECTDIR}/Sources/Gest_Energy.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -p$(MP_PROCESSOR_OPTION) -I".." -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/Sources/Gest_Energy.o   Sources/Gest_Energy.c 
	@${DEP_GEN} -d ${OBJECTDIR}/Sources/Gest_Energy.o 
	@${FIXDEPS} "${OBJECTDIR}/Sources/Gest_Energy.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
else
${OBJECTDIR}/Sources/BlueCom.o: Sources/BlueCom.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/Sources 
	@${RM} ${OBJECTDIR}/Sources/BlueCom.o.d 
	@${RM} ${OBJECTDIR}/Sources/BlueCom.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -I".." -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/Sources/BlueCom.o   Sources/BlueCom.c 
	@${DEP_GEN} -d ${OBJECTDIR}/Sources/BlueCom.o 
	@${FIXDEPS} "${OBJECTDIR}/Sources/BlueCom.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/Sources/Interrupts.o: Sources/Interrupts.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/Sources 
	@${RM} ${OBJECTDIR}/Sources/Interrupts.o.d 
	@${RM} ${OBJECTDIR}/Sources/Interrupts.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -I".." -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/Sources/Interrupts.o   Sources/Interrupts.c 
	@${DEP_GEN} -d ${OBJECTDIR}/Sources/Interrupts.o 
	@${FIXDEPS} "${OBJECTDIR}/Sources/Interrupts.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/Sources/main.o: Sources/main.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/Sources 
	@${RM} ${OBJECTDIR}/Sources/main.o.d 
	@${RM} ${OBJECTDIR}/Sources/main.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -I".." -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/Sources/main.o   Sources/main.c 
	@${DEP_GEN} -d ${OBJECTDIR}/Sources/main.o 
	@${FIXDEPS} "${OBJECTDIR}/Sources/main.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/Sources/UARTIntC.o: Sources/UARTIntC.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/Sources 
	@${RM} ${OBJECTDIR}/Sources/UARTIntC.o.d 
	@${RM} ${OBJECTDIR}/Sources/UARTIntC.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -I".." -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/Sources/UARTIntC.o   Sources/UARTIntC.c 
	@${DEP_GEN} -d ${OBJECTDIR}/Sources/UARTIntC.o 
	@${FIXDEPS} "${OBJECTDIR}/Sources/UARTIntC.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/Sources/tick.o: Sources/tick.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/Sources 
	@${RM} ${OBJECTDIR}/Sources/tick.o.d 
	@${RM} ${OBJECTDIR}/Sources/tick.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -I".." -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/Sources/tick.o   Sources/tick.c 
	@${DEP_GEN} -d ${OBJECTDIR}/Sources/tick.o 
	@${FIXDEPS} "${OBJECTDIR}/Sources/tick.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/Sources/RTTTLtone.o: Sources/RTTTLtone.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/Sources 
	@${RM} ${OBJECTDIR}/Sources/RTTTLtone.o.d 
	@${RM} ${OBJECTDIR}/Sources/RTTTLtone.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -I".." -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/Sources/RTTTLtone.o   Sources/RTTTLtone.c 
	@${DEP_GEN} -d ${OBJECTDIR}/Sources/RTTTLtone.o 
	@${FIXDEPS} "${OBJECTDIR}/Sources/RTTTLtone.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/Sources/Gest_Energy.o: Sources/Gest_Energy.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/Sources 
	@${RM} ${OBJECTDIR}/Sources/Gest_Energy.o.d 
	@${RM} ${OBJECTDIR}/Sources/Gest_Energy.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -I".." -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/Sources/Gest_Energy.o   Sources/Gest_Energy.c 
	@${DEP_GEN} -d ${OBJECTDIR}/Sources/Gest_Energy.o 
	@${FIXDEPS} "${OBJECTDIR}/Sources/Gest_Energy.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
dist/${CND_CONF}/${IMAGE_TYPE}/DetectHeat.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_LD} $(MP_EXTRA_LD_PRE)   -p$(MP_PROCESSOR_OPTION_LD)  -w -x -u_DEBUG -m"$(BINDIR_)$(TARGETBASE).map" -w -l"/C:/MCC18/lib"  -z__MPLAB_BUILD=1  -u_CRUNTIME -z__MPLAB_DEBUG=1 -z__MPLAB_DEBUGGER_PK3=1 $(MP_LINKER_DEBUG_OPTION) -l ${MP_CC_DIR}\\..\\lib  -o dist/${CND_CONF}/${IMAGE_TYPE}/DetectHeat.${IMAGE_TYPE}.${OUTPUT_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}   
else
dist/${CND_CONF}/${IMAGE_TYPE}/DetectHeat.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_LD} $(MP_EXTRA_LD_PRE)   -p$(MP_PROCESSOR_OPTION_LD)  -w  -m"$(BINDIR_)$(TARGETBASE).map" -w -l"/C:/MCC18/lib"  -z__MPLAB_BUILD=1  -u_CRUNTIME -l ${MP_CC_DIR}\\..\\lib  -o dist/${CND_CONF}/${IMAGE_TYPE}/DetectHeat.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}   
endif

.pre:
	@echo "--------------------------------------"
	@echo "User defined pre-build step: []"
	@
	@echo "--------------------------------------"

# Subprojects
.build-subprojects:


# Subprojects
.clean-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r build/default
	${RM} -r dist/default

# Enable dependency checking
.dep.inc: .depcheck-impl

DEPFILES=$(shell mplabwildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif
