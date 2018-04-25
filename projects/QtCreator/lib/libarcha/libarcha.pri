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
#   File: libarcha.pri
#
# Author: $author$
#   Date: 4/24/2018
#
# QtCreator .pri file for archa library libarcha
########################################################################

########################################################################
# libarcha

# libarcha TARGET
#
libarcha_TARGET = archa
libarcha_TEMPLATE = lib
libarcha_CONFIG += staticlib

# libarcha INCLUDEPATH
#
libarcha_INCLUDEPATH += \
$${archa_INCLUDEPATH} \

# libarcha DEFINES
#
libarcha_DEFINES += \
$${archa_DEFINES} \

########################################################################
# libarcha OBJECTIVE_HEADERS
#
#libarcha_OBJECTIVE_HEADERS += \
#$${ARCHA_SRC}/archa/base/Base.hh \

# libarcha OBJECTIVE_SOURCES
#
#libarcha_OBJECTIVE_SOURCES += \
#$${ARCHA_SRC}/archa/base/Base.mm \

########################################################################
# libarcha HEADERS
#
libarcha_HEADERS += \
$${ARCHA_SRC}/xos/lib/archa/version.hpp \

# libarcha SOURCES
#
libarcha_SOURCES += \
$${ARCHA_SRC}/xos/lib/archa/version.cpp \

########################################################################



