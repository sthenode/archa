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
#   File: archa.pri
#
# Author: $author$
#   Date: 4/24/2018
#
# QtCreator .pri file for archa executable archa
########################################################################

########################################################################
# archa

# archa_exe TARGET
#
archa_exe_TARGET = archa

# archa_exe INCLUDEPATH
#
archa_exe_INCLUDEPATH += \
$${archa_INCLUDEPATH} \

# archa_exe DEFINES
#
archa_exe_DEFINES += \
$${archa_DEFINES} \

########################################################################
# archa_exe OBJECTIVE_HEADERS
#
#archa_exe_OBJECTIVE_HEADERS += \
#$${ARCHA_SRC}/archa/base/Base.hh \

# archa_exe OBJECTIVE_SOURCES
#
#archa_exe_OBJECTIVE_SOURCES += \
#$${ARCHA_SRC}/archa/base/Base.mm \

########################################################################
# archa_exe HEADERS
#
archa_exe_HEADERS += \
$${CRONO_SRC}/xos/base/timezone.hpp \
$${CRONO_SRC}/xos/base/time.hpp \
$${CRONO_SRC}/xos/base/date.hpp \
$${ARCHA_SRC}/xos/fs/time.hpp \
$${ARCHA_SRC}/xos/fs/path_separator.hpp \
$${ARCHA_SRC}/xos/fs/path.hpp \
$${ARCHA_SRC}/xos/fs/entry.hpp \
$${ARCHA_SRC}/xos/fs/directory/entry.hpp \
$${ARCHA_SRC}/xos/fs/directory/path.hpp \
$${ARCHA_SRC}/xos/os/os/os.hpp \
$${ARCHA_SRC}/xos/os/os/fs.hpp \
$${ARCHA_SRC}/xos/os/posix/fs/entry.hpp \
$${ARCHA_SRC}/xos/os/posix/fs/path.hpp \
$${ARCHA_SRC}/xos/os/posix/fs/directory/entry.hpp \
$${ARCHA_SRC}/xos/os/posix/fs/directory/path.hpp \
$${ARCHA_SRC}/xos/os/fs/entry.hpp \
$${ARCHA_SRC}/xos/os/fs/path.hpp \
$${ARCHA_SRC}/xos/os/fs/directory/entry.hpp \
$${ARCHA_SRC}/xos/os/fs/directory/path.hpp \
$${ARCHA_SRC}/xos/app/console/archa/branch.hpp \
$${ARCHA_SRC}/xos/app/console/archa/main_opt.hpp \
$${ARCHA_SRC}/xos/app/console/archa/main.hpp \
$${FILA_SRC}/xos/console/main_main.hpp \

# archa_exe SOURCES
#
archa_exe_SOURCES += \
$${CRONO_SRC}/xos/base/timezone.cpp \
$${CRONO_SRC}/xos/base/date.cpp \
$${ARCHA_SRC}/xos/fs/time.cpp \
$${ARCHA_SRC}/xos/fs/path_separator.cpp \
$${ARCHA_SRC}/xos/os/os/os.cpp \
$${ARCHA_SRC}/xos/os/os/fs.cpp \
$${ARCHA_SRC}/xos/os/posix/fs/directory/entry.cpp \
$${ARCHA_SRC}/xos/os/posix/fs/directory/path.cpp \
$${ARCHA_SRC}/xos/app/console/archa/branch.cpp \
$${ARCHA_SRC}/xos/app/console/archa/main_opt.cpp \
$${ARCHA_SRC}/xos/app/console/archa/main.cpp \
$${FILA_SRC}/xos/console/main_main.cpp \

########################################################################
# archa_exe FRAMEWORKS
#
archa_exe_FRAMEWORKS += \
$${archa_FRAMEWORKS} \

# archa_exe LIBS
#
archa_exe_LIBS += \
$${archa_LIBS} \

