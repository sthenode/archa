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
#   File: libarcha.pro
#
# Author: $author$
#   Date: 4/24/2018
#
# QtCreator .pro file for archa library libarcha
########################################################################
include(../../../../../build/QtCreator/archa.pri)
include(../../../../QtCreator/archa.pri)
include(../../archa.pri)
include(../../../../QtCreator/lib/libarcha/libarcha.pri)

TARGET = $${libarcha_TARGET}
TEMPLATE = $${libarcha_TEMPLATE}
CONFIG += $${libarcha_CONFIG}

########################################################################
# INCLUDEPATH
#
INCLUDEPATH += \
$${libarcha_INCLUDEPATH} \

# DEFINES
# 
DEFINES += \
$${libarcha_DEFINES} \

########################################################################
# OBJECTIVE_HEADERS
#
OBJECTIVE_HEADERS += \
$${libarcha_OBJECTIVE_HEADERS} \

# OBJECTIVE_SOURCES
#
SOURCES += \
$${libarcha_OBJECTIVE_SOURCES} \

########################################################################
# HEADERS
#
HEADERS += \
$${libarcha_HEADERS} \

# SOURCES
#
SOURCES += \
$${libarcha_SOURCES} \
$${OBJECTIVE_SOURCES} \

########################################################################


