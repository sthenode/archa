///////////////////////////////////////////////////////////////////////
/// Copyright (c) 1988-2018 $organization$
///
/// This software is provided by the author and contributors ``as is'' 
/// and any express or implied warranties, including, but not limited to, 
/// the implied warranties of merchantability and fitness for a particular 
/// purpose are disclaimed. In no event shall the author or contributors 
/// be liable for any direct, indirect, incidental, special, exemplary, 
/// or consequential damages (including, but not limited to, procurement 
/// of substitute goods or services; loss of use, data, or profits; or 
/// business interruption) however caused and on any theory of liability, 
/// whether in contract, strict liability, or tort (including negligence 
/// or otherwise) arising in any way out of the use of this software, 
/// even if advised of the possibility of such damage.
///
///   File: entry.hpp
///
/// Author: $author$
///   Date: 4/27/2018
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_OS_POSIX_FS_DIRECTORY_ENTRY_HPP
#define _XOS_OS_POSIX_FS_DIRECTORY_ENTRY_HPP

#include "xos/fs/directory/entry.hpp"

namespace xos {
namespace os {
namespace posix {
namespace fs {
namespace directory {

typedef implement_base entry_implementt_implements;
///////////////////////////////////////////////////////////////////////
///  Class: entry_implementt
///////////////////////////////////////////////////////////////////////
template <class TImplements = entry_implementt_implements>
class _EXPORT_CLASS entry_implementt: virtual public TImplements {
public:
    typedef TImplements implements;
};
typedef entry_implementt<> entry_implement;

typedef entry_implement entryt_implements;
typedef base entryt_extends;
///////////////////////////////////////////////////////////////////////
///  Class: entryt
///////////////////////////////////////////////////////////////////////
template <class TImplements = entryt_implements, class TExtends = entryt_extends>
class _EXPORT_CLASS entryt: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;

    entryt(const entryt &copy) {
    }
    entryt() {
    }
    virtual ~entryt() {
    }
};
typedef entryt<> entry;

} /// namespace directory
} /// namespace fs
} /// namespace posix
} /// namespace os
} /// namespace xos

#endif /// _XOS_OS_POSIX_FS_DIRECTORY_ENTRY_HPP 
