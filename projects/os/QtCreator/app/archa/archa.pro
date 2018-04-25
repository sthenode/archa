########################################################################
# Copyright (c) 1988-2018 $organization$
#
# This software is provided by the author and contributors ``as is''
# and any express or implied warranties, including, but not limited to,
# the implied warranties of merchantability and fitness for a particular
# purpose are disclaimed. In no event shall the author or contributors
# be liable for any direct, indirect, incidental, special, exemplary,
# or consequential damages (including, but not limited to, procurement
# of substitute goods or services; loss of use, data, or profits; or
# business interruption) however caused and on any theory of liability,
# whether in contract, strict liability, or tort (including negligence
# or otherwise) arising in any way out of the use of this software,
# even if advised of the possibility of such damage.
#
#   File: archa.pro
#
# Author: $author$
#   Date: 4/24/2018
#
# QtCreator .pro file for archa executable archa
########################################################################
include(../../../../../build/QtCreator/archa.pri)
include(../../../../QtCreator/archa.pri)
include(../../archa.pri)
include(../../../../QtCreator/app/archa/archa.pri)

TARGET = $${archa_exe_TARGET}

########################################################################
# INCLUDEPATH
#
INCLUDEPATH += \
$${archa_exe_INCLUDEPATH} \

# DEFINES
# 
DEFINES += \
$${archa_exe_DEFINES} \

########################################################################
# OBJECTIVE_HEADERS
#
OBJECTIVE_HEADERS += \
$${archa_exe_OBJECTIVE_HEADERS} \

# OBJECTIVE_SOURCES
#
SOURCES += \
$${archa_exe_OBJECTIVE_SOURCES} \

########################################################################
# HEADERS
#
HEADERS += \
$${archa_exe_HEADERS} \

# SOURCES
#
SOURCES += \
$${archa_exe_SOURCES} \
$${OBJECTIVE_SOURCES} \

########################################################################
# FRAMEWORKS
#
FRAMEWORKS += \
$${archa_exe_FRAMEWORKS} \

# LIBS
#
LIBS += \
$${archa_exe_LIBS} \
$${FRAMEWORKS} \


