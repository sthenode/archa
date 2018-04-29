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
#ifndef _XOS_OS_POSIX_FS_DIRECTORY_PATH_HPP
#define _XOS_OS_POSIX_FS_DIRECTORY_PATH_HPP

#include "xos/os/posix/fs/directory/entry.hpp"
#include "xos/fs/directory/path.hpp"

namespace xos {
namespace os {
namespace posix {
namespace fs {
namespace directory {

typedef DIR* path_attached_t;
typedef int path_unattached_t;
enum { path_unattached = 0};

///////////////////////////////////////////////////////////////////////
///  Class: patht
///////////////////////////////////////////////////////////////////////
template 
<class TOpener = xos::fs::directory::path,
 class TAttacher = attachert
 <path_attached_t, path_unattached_t, path_unattached, TOpener>,
 class TAttached = attachedt
 <path_attached_t, path_unattached_t, path_unattached, TAttacher>,
 class TOpened = openedt
 <path_attached_t, path_unattached_t, path_unattached, TAttacher, TAttached>,
 class TImplements = TAttacher, class TExtends = TOpened>

class _EXPORT_CLASS patht: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;
    typedef patht derives;

    typedef directory::entry entry_t;
    
    typedef typename TImplements::attached_t attached_t;
    typedef typename TImplements::unattached_t unattached_t;
    enum { unattached = TImplements::unattached };

    typedef typename TImplements::string_t string_t;
    typedef typename string_t::char_t char_t;
    typedef typename string_t::end_t end_t;
    enum { endof = string_t::endof };

    patht(const patht &copy) {
    }
    patht() {
    }
    virtual ~patht() {
        if (!(this->closed())) {
            const open_exception e(close_failed);
            LOG_ERROR("...failed on this->closed() throw (const open_exception e(close_failed))...");
            throw (e);
        }
    }

    virtual bool open(const string_t& name) {
        const char* chars = 0;
        if ((chars = name.has_chars())) {
            return open(chars);
        }
        return false;
    }
    virtual bool open(const char* name) {
        if ((this->closed())) {
            if ((name) && (name[0])) {
                attached_t d = 0;

                LOG_DEBUG("::opendir(name = \"" << name << "\")...");
                if ((d = opendir(name))) {
                    LOG_DEBUG("...::opendir(name = \"" << name << "\")");
                    this->set_name(name);
                    this->attach_opened(d);
                    get_first_ = &derives::get_first;
                    return true;
                } else {
                    LOG_ERROR("...failed " << errno << " on ::opendir(\"" << name << "\")");
                }
            }
        }
        return false;
    }
    virtual bool close() {
        attached_t d = 0;
        get_first_ = 0;
        get_next_ = 0;

        if ((d = this->detach())) {
            int err = 0;

            LOG_DEBUG("::closedir(d)...");
            if (!(err = ::closedir(d))) {
                LOG_DEBUG("...::closedir(d)");
                return true;
            } else {
                LOG_ERROR("...failed " << err << " on ::closedir()");
            }
        }
        return false;
    }

    virtual entry_t* get_first_entry() {
        if ((get_first_)) {
            return (this->*get_first_)();
        }
        return 0;
    }
    virtual entry_t* get_next_entry() {
        if ((get_next_)) {
            return (this->*get_next_)();
        }
        return 0;
    }

    virtual const char_t* set_name(const wchar_t* chars, size_t length) {
        name_.assign(chars, length);
        return name_.c_str();
    }
    virtual const char_t* set_name(const wchar_t* chars) {
        name_.assign(chars);
        return name_.c_str();
    }
    virtual const char_t* set_name(const char* chars, size_t length) {
        name_.assign(chars, length);
        return name_.c_str();
    }
    virtual const char_t* set_name(const char* chars) {
        name_.assign(chars);
        return name_.c_str();
    }
    virtual const char_t* name(size_t& length) const {
        length = name_.length();
        return name_.c_str();
    }
    virtual const char_t* name() const {
        return name_.c_str();
    }

protected:
    virtual entry_t* get_first_again() {
        return 0;
    }
    virtual entry_t* get_first() {
        get_first_ = &derives::get_first_again;
        get_next_ = &derives::get_next;
        return get_next();
    }
    virtual entry_t* get_next() {
        attached_t d = 0;

        if ((d = this->attached_to())) {
            const struct dirent* dirent = 0;

            LOG_DEBUG("::readdir(d)...");
            if ((dirent = ::readdir(d))) {
                LOG_DEBUG("...::readdir(d)");
                entry_.assign(name_.chars(), dirent);
                return &entry_;
            } else {
                LOG_DEBUG("...failed " << errno << " on ::readdir()");
            }
        }
        return 0;
    }

protected:
    typedef entry_t* (derives::*get_t)();
    get_t get_first_, get_next_;
    entry_t entry_;
    string_t name_;
};
typedef patht<> path;

} /// namespace directory
} /// namespace fs
} /// namespace posix
} /// namespace os
} /// namespace xos

#endif /// _XOS_OS_POSIX_FS_DIRECTORY_PATH_HPP 
