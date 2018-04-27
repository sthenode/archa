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
///   Date: 4/26/2018
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_FS_DIRECTORY_ENTRY_HPP
#define _XOS_FS_DIRECTORY_ENTRY_HPP

#include "xos/fs/entry.hpp"

namespace xos {
namespace fs {
namespace directory {

///////////////////////////////////////////////////////////////////////
///  Class: entryt
///////////////////////////////////////////////////////////////////////
template 
<class TImplements = fs::entry::implements, class TExtends = fs::entry>

class _EXPORT_CLASS entryt: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;

    typedef typename TExtends::string_t string_t;
    typedef typename string_t::char_t char_t;
    typedef typename string_t::end_t end_t;
    enum { endof = string_t::endof };

    entryt(const entryt &copy)
    : extends(copy), is_current_(copy.is_current()), is_parent_(copy.is_parent()) {
    }
    entryt(): is_current_(false), is_parent_(false) {
    }
    virtual ~entryt() {
    }
    
    virtual bool is_circular() const {
        return (is_current_ || is_parent_);
    }

    virtual bool set_is_current(bool to = true) {
        is_parent_ = (false);
        is_current_ = to;
        return is_current_;
    }
    virtual bool is_current() const {
        return is_current_;
    }

    virtual bool set_is_parent(bool to = true) {
        is_current_ = (false);
        is_parent_ = to;
        return is_parent_;
    }
    virtual bool is_parent() const {
        return is_parent_;
    }

    virtual const char* current_name_chars() const {
        return ".";
    }
    virtual const char* parent_name_chars() const {
        return "..";
    }

protected:
    virtual void on_set_name() {
        set_is_current(false);
        set_is_parent(false);
        if (!(this->name_.compare(current_name_chars()))) {
            set_is_current();
        } else {
            if (!(this->name_.compare(parent_name_chars()))) {
                set_is_parent();
            } else {
            }
        }
    }

protected:
    bool is_current_, is_parent_;
};
typedef entryt<> entry;

} /// namespace directory
} /// namespace fs
} /// namespace xos

#endif /// _XOS_FS_DIRECTORY_ENTRY_HPP 
