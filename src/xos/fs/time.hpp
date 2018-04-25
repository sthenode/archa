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
///   File: time.hpp
///
/// Author: $author$
///   Date: 4/24/2018
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_FS_TIME_HPP
#define _XOS_FS_TIME_HPP

#include "xos/base/date.hpp"
#include "xos/base/chars.hpp"

#define XOS_FS_TIME_WHICH_NAME_NONE "none"
#define XOS_FS_TIME_WHICH_NAME_MODIFIED "modified"
#define XOS_FS_TIME_WHICH_NAME_ACCESSED "accessed"
#define XOS_FS_TIME_WHICH_NAME_CHANGED "changed"
#define XOS_FS_TIME_WHICH_NAME_CREATED "created"

namespace xos {
namespace fs {

typedef int time_when_which;
enum {
    time_when_none     = 0,

    time_when_modified = 1,
    time_when_accessed = (time_when_modified << 1),
    time_when_changed  = (time_when_accessed << 1),
    time_when_created  = (time_when_changed << 1),

    first_time_when = time_when_modified,
    last_time_when = time_when_created,
    next_time_when = (last_time_when << 1),

    time_when_any = (next_time_when - 1)
};

typedef implement_base time_when_implements;
typedef base time_when_extends;
///////////////////////////////////////////////////////////////////////
///  Class: time_whent
///////////////////////////////////////////////////////////////////////
template
<class TImplements = time_when_implements, class TExtends = time_when_extends>
class _EXPORT_CLASS time_whent: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;

    time_whent(time_when_which which): which_(which) {
    }
    time_whent(const time_whent& copy): which_(copy.which()) {
    }
    time_whent(): which_(time_when_none) {
    }
    virtual ~time_whent() {
    }

    virtual time_whent& operator = (time_when_which which) {
        which_ = which;
        return *this;
    }
    virtual time_whent& operator |= (time_when_which which) {
        which_ |= which;
        return *this;
    }
    virtual time_whent& operator &= (time_when_which which) {
        which_ &= which;
        return *this;
    }

    virtual time_when_which which() const {
        return which_;
    }
    virtual operator time_when_which() const {
        return which_;
    }

    static time_when_which of(const char* name) {
        if ((chars_t::compare_uncased(name, XOS_FS_TIME_WHICH_NAME_MODIFIED))) {
            if ((chars_t::compare_uncased(name, XOS_FS_TIME_WHICH_NAME_ACCESSED))) {
                if ((chars_t::compare_uncased(name, XOS_FS_TIME_WHICH_NAME_CHANGED))) {
                    if ((chars_t::compare_uncased(name, XOS_FS_TIME_WHICH_NAME_CREATED))) {
                        return time_when_none;
                    } else {
                        return time_when_created;
                    }
                } else {
                    return time_when_changed;
                }
            } else {
                return time_when_accessed;
            }
        } else {
            return time_when_modified;
        }
        return time_when_none;
    }
    static const char* name(time_when_which of) {
        switch (of) {
        case time_when_modified: return XOS_FS_TIME_WHICH_NAME_MODIFIED;
        case time_when_accessed: return XOS_FS_TIME_WHICH_NAME_ACCESSED;
        case time_when_changed: return XOS_FS_TIME_WHICH_NAME_CHANGED;
        case time_when_created: return XOS_FS_TIME_WHICH_NAME_CREATED;
        }
        return XOS_FS_TIME_WHICH_NAME_NONE;
    }

protected:
    time_when_which which_;
};
typedef time_whent<> time_when;

typedef xos::date::implements time_implementt_implements;
///////////////////////////////////////////////////////////////////////
///  Class: time_implementt
///////////////////////////////////////////////////////////////////////
template <class TImplements = time_implementt_implements>
class _EXPORT_CLASS time_implementt: virtual public TImplements {
public:
    typedef TImplements implements;
};
typedef time_implementt<> time_implement;

typedef time_implement timet_implements;
typedef xos::date timet_extends;
///////////////////////////////////////////////////////////////////////
///  Class: timet
///////////////////////////////////////////////////////////////////////
template <class TImplements = timet_implements, class TExtends = timet_extends>
class _EXPORT_CLASS timet: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;

    timet(const time_when& when): when_(when) {
    }
    timet(time_when_which which): when_(which) {
    }
    timet(const timet &copy): extends(copy) {
    }
    timet() {
    }
    virtual ~timet() {
    }

    virtual time_when set_when(const time_when& to) {
        when_ = to;
        return when_;
    }
    virtual time_when set_when(time_when_which to) {
        when_ = to;
        return when_;
    }
    virtual time_when when() const {
        return when_;
    }

    virtual time_when_which set_which(time_when_which to) {
        when_ = to;
        return when_.which();
    }
    virtual time_when_which which() const {
        return when_.which();
    }

protected:
    time_when when_;
};
typedef timet<> time;

} /// namespace fs
} /// namespace xos

#endif /// _XOS_FS_TIME_HPP 
