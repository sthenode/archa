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
///   Date: 4/26/2018
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_FS_DIRECTORY_PATH_HPP
#define _XOS_FS_DIRECTORY_PATH_HPP

#include "xos/fs/directory/entry.hpp"
#include "xos/base/opened.hpp"

namespace xos {
namespace fs {
namespace directory {

///////////////////////////////////////////////////////////////////////
///  Class: patht
///////////////////////////////////////////////////////////////////////
template 
<class TImplements = openert<directory::entry::implements> >

class _EXPORT_CLASS patht: virtual public TImplements {
public:
    typedef TImplements implements;

    typedef typename TImplements::string_t string_t;
    typedef typename string_t::char_t char_t;
    typedef typename string_t::end_t end_t;
    enum { endof = string_t::endof };

    virtual bool open(const char* chars) {
        const string_t name(chars);
        return open(name);
    }
    virtual bool open(const wchar_t* chars) {
        const string_t name(chars);
        return open(name);
    }
    virtual bool open(const string_t& name) {
        return false;
    }
    virtual bool close() {
        return false;
    }
};
typedef patht<> path;

} /// namespace directory
} /// namespace fs
} /// namespace xos

#endif /// _XOS_FS_DIRECTORY_PATH_HPP 
