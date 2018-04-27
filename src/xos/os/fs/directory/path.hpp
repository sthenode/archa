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
///   File: path.hpp
///
/// Author: $author$
///   Date: 4/27/2018
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_OS_FS_DIRECORY_PATH_HPP
#define _XOS_OS_FS_DIRECORY_PATH_HPP

#include "xos/fs/directory/entry.hpp"

namespace xos {
namespace os {
namespace fs {
namespace directory {

typedef implement_base path_implementt_implements;
///////////////////////////////////////////////////////////////////////
///  Class: path_implementt
///////////////////////////////////////////////////////////////////////
template <class TImplements = path_implementt_implements>
class _EXPORT_CLASS path_implementt: virtual public TImplements {
public:
    typedef TImplements implements;
};
typedef path_implementt<> path_implement;

typedef path_implement patht_implements;
typedef base patht_extends;
///////////////////////////////////////////////////////////////////////
///  Class: patht
///////////////////////////////////////////////////////////////////////
template <class TImplements = patht_implements, class TExtends = patht_extends>
class _EXPORT_CLASS patht: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;

    patht(const patht &copy) {
    }
    patht() {
    }
    virtual ~patht() {
    }
};
typedef patht<> path;

} /// namespace directory
} /// namespace fs
} /// namespace os
} /// namespace xos

#endif /// _XOS_OS_FS_DIRECORY_PATH_HPP 
