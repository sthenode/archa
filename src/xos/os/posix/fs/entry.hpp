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
#ifndef _XOS_OS_POSIX_FS_ENTRY_HPP
#define _XOS_OS_POSIX_FS_ENTRY_HPP

#include "xos/fs/directory/entry.hpp"
#include "xos/io/logger.hpp"

#include <sys/stat.h>
#include <utime.h>

#define S_IRWX (S_IRWXU | S_IRGRP | S_IXGRP | S_IROTH | S_IXOTH)
#define S_IRW (S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH)
#define S_IR (S_IRUSR | S_IRGRP | S_IROTH)

namespace xos {
namespace os {
namespace posix {
namespace fs {

typedef xos::fs::time time;
typedef xos::fs::time_when time_when;
enum {
    time_when_none     = xos::fs::time_when_none,
    time_when_modified = xos::fs::time_when_modified,
    time_when_accessed = xos::fs::time_when_accessed,
    time_when_changed  = xos::fs::time_when_changed,
    time_when_created  = xos::fs::time_when_created
};
typedef xos::fs::entry_type entry_type;
enum {
    entry_type_none          = xos::fs::entry_type_none,
    entry_type_file          = xos::fs::entry_type_file,
    entry_type_directory     = xos::fs::entry_type_directory,
    entry_type_symbolic_link = xos::fs::entry_type_symbolic_link,
    entry_type_hard_link     = xos::fs::entry_type_hard_link,
    entry_type_block_device  = xos::fs::entry_type_block_device,
    entry_type_char_device   = xos::fs::entry_type_char_device,
    entry_type_pipe          = xos::fs::entry_type_pipe,
    entry_type_socket        = xos::fs::entry_type_socket,
};
typedef xos::fs::entry_size_t entry_size_t;
typedef xos::fs::entry_ssize_t entry_ssize_t;

typedef implement_base statt_implements;
typedef base statt_extends;
///////////////////////////////////////////////////////////////////////
///  Class: statt
///////////////////////////////////////////////////////////////////////
template 
<class TImplements = statt_implements, class TExtends = statt_extends>

class _EXPORT_CLASS statt: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;

    typedef struct stat struct_stat_t;
    
    statt(const statt &copy) {
        ::memcpy(&struct_stat_, &copy.stat(), sizeof(struct_stat_));
    }
    statt() {
        ::memset(&struct_stat_, 0, sizeof(struct_stat_));
    }
    virtual ~statt() {
    }

    virtual struct_stat_t& struct_stat() const { 
        return (struct_stat_t&)struct_stat_; 
    }
    virtual struct_stat_t* operator & () const { 
        return (struct_stat_t*)&struct_stat_; 
    }
    virtual operator struct_stat_t&() const { 
        return (struct_stat_t&)struct_stat_; 
    }

protected:
    struct_stat_t struct_stat_;
};
typedef statt<> stat_t;

typedef implement_base utimbuft_implements;
typedef base utimbuft_extends;
///////////////////////////////////////////////////////////////////////
///  Class: utimbuft
///////////////////////////////////////////////////////////////////////
template 
<class TImplements = utimbuft_implements, class TExtends = utimbuft_extends>

class _EXPORT_CLASS utimbuft: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;

    typedef struct utimbuf struct_utimbuf_t;
    
    utimbuft(const utimbuft &copy) {
        ::memcpy(&struct_utimbuf_, &copy.utimbuf(), sizeof(struct_utimbuf_));
    }
    utimbuft() {
        ::memset(&struct_utimbuf_, 0, sizeof(struct_utimbuf_));
    }
    virtual ~utimbuft() {
    }

    virtual struct_utimbuf_t& utimbuf() const { 
        return (struct_utimbuf_t&)struct_utimbuf_; 
    }
    virtual struct_utimbuf_t* operator & () const { 
        return (struct_utimbuf_t*)&struct_utimbuf_; 
    }
    virtual operator struct_utimbuf_t&() const { 
        return (struct_utimbuf_t&)struct_utimbuf_; 
    }

protected:
    struct_utimbuf_t struct_utimbuf_;
};
typedef utimbuft<> utimbuf_t;

typedef xos::fs::entry::implements entryt_implements;
typedef xos::fs::entry entryt_extends;
///////////////////////////////////////////////////////////////////////
///  Class: entryt
///////////////////////////////////////////////////////////////////////
template 
<class TImplements = entryt_implements, class TExtends = entryt_extends>

class _EXPORT_CLASS entryt: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;

    typedef typename TExtends::string_t string_t;
    typedef typename string_t::char_t char_t;
    typedef typename string_t::end_t end_t;
    enum { endof = string_t::endof };

    entryt(const entryt &copy) {
    }
    entryt() {
    }
    virtual ~entryt() {
    }

    virtual entry_type exists(const char_string& path) {
        const char* chars = 0;
        if ((chars = path.has_chars())) {
            return exists(chars);
        }
        return entry_type_none;
    }
    virtual entry_type exists(const char* chars) {
        if ((chars)) {
            if ((is_found(chars))) {
                entry_type type = entry_type_none;
                if (entry_type_none != (type = get_found_attributes())) {
                    return type;
                }
            }
        }
        return entry_type_none;
    }

protected:
    virtual bool is_found(const char* path) {
        if ((path)) {
            int err = 0;
            LOG_DEBUG("::stat(path = \"" << path << "\", &st_)...");
            if (!(err = ::stat(path, &st_))) {
                LOG_DEBUG("::lstat(path = \"" << path << "\", &lst_)...");
                if (!(err = ::lstat(path, &lst_))) {
                    const char* name = path;
                    for (char c = *(path); c; c = *(++path)) {
                        if ((is_directory_separator(c))) {
                            name = path+1;
                        }
                    }
                    if ((name[0])) {
                        this->set_name(name);
                    }
                    return true;
                } else {
                    LOG_DEBUG("failed " << errno << " on ::lstat(path = \"" << path << "\",...)");
                }
            } else {
                LOG_DEBUG("failed " << errno << " on ::stat(path = \"" << path << "\",...)");
            }
        }
        return false;
    }
    virtual entry_type get_found(const char* path) {
        char_string path_name(path);
        if ((path = this->name())) {
            const char* chars = 0;
            if ((chars = path_name.has_chars())) {
                path_name.append(&directory_separator(), 1);
            }
            path_name.append(path);
            if ((chars = path_name.has_chars())) {
                if ((is_found(chars))) {
                    return get_found_attributes(this->type());
                }
            }
        }
        return entry_type_none;
    }
    virtual entry_type get_found_attributes(entry_type type = entry_type_none) {
        entry_ssize_t size = -1;
        if (0 <= (size = get_found_size())) {
            if (entry_type_none != (type = get_found_type(type))) {
                time_when times = time_when_none;
                if (time_when_none != (times = get_found_times())) {
                    return type;
                }
            }
        }
        return entry_type_none;
    }
    virtual time_when get_found_times() {
        time_when time = time_when_none;
        const struct stat& st = st_;
        bool is_local = false;

        if ((to_time(this->time_modified_, st.st_mtime, is_local))) {
            LOG_DEBUG("time modified  = " << this->time_modified_.month() << "/" << this->time_modified_.day() << "/" << this->time_modified_.year());
            time |= time_when_modified;
        }
        if ((to_time(this->time_accessed_, st.st_atime, is_local))) {
            LOG_DEBUG("time accessed  = " << this->time_accessed_.month() << "/" << this->time_accessed_.day() << "/" << this->time_accessed_.year());
            time |= time_when_accessed;
        }
        if ((to_time(this->time_changed_, st.st_ctime, is_local))) {
            LOG_DEBUG("time changed  = " << this->time_changed_.month() << "/" << this->time_changed_.day() << "/" << this->time_changed_.year());
            time |= time_when_changed;
        }
        this->set_times(time);
        return time;
    }
    virtual entry_type get_found_type(entry_type type = entry_type_none) {
        const struct stat& st = st_;
        const struct stat& lst = lst_;
        mode_t fmt;

        if (S_IFDIR == (S_IFDIR & st.st_mode)) {
            LOG_DEBUG("...S_IFDIR");
            type &= ~entry_type_file;
            type |= entry_type_directory;
        } else {
            type &= ~entry_type_directory;
            type |= entry_type_file;
        }

        if (S_IFLNK == (fmt = (S_IFMT & (lst.st_mode)))) {
            LOG_DEBUG("...S_IFLNK");
            type &= ~entry_type_hard_link;
            type |= entry_type_symbolic_link;
        }
        this->set_type(type);
        return type;
    }

    virtual entry_ssize_t get_found_size() {
        const struct stat& st = st_;
        off_t size = -1;

        if (0 <= (size = st.st_size)) {
            this->set_size(size);
        }
        return size;
    }

    virtual xos::fs::time* to_time
    (xos::fs::time& to, const time_t& from, bool is_local = false) {
        struct tm tm;
        if ((to_system_time(tm, from, is_local))) {
            return to_time(to, tm, is_local);
        }
        return 0;
    }
    virtual time_t* from_time
    (time_t& to, const xos::fs::time& from, bool is_local = false) {
        struct tm tm;
        if ((from_time(tm, from, is_local))) {
            return from_system_time(to, tm, is_local);
        }
        return 0;
    }
    virtual xos::fs::time* to_time
    (xos::fs::time& to, const struct tm& from, bool is_local = false) {
        to.clear();
        to.set_year(from.tm_year+1900);
        to.set_month(from.tm_mon+1);
        to.set_day(from.tm_mday);
        to.set_hour(from.tm_hour);
        to.set_minute(from.tm_min);
        to.set_second(from.tm_sec);
        return &to;
    }
    virtual struct tm* from_time
    (struct tm& to, const xos::fs::time& from, bool is_local = false) {
        memset(&to, 0, sizeof(struct tm));
        to.tm_year = from.year()-1900;
        to.tm_mon = from.month()-1;
        to.tm_mday = from.day();
        to.tm_hour = from.hour();
        to.tm_min = from.minute();
        to.tm_sec = from.second();
        return &to;
    }

    virtual struct tm* to_system_time
    (struct tm& to, const time_t& from, bool is_local = false) const {
        struct tm* t = 0;
        if (is_local) {
            LOG_DEBUG("::localtime_r(&from, &to)...");
            if (!(t = ::localtime_r(&from, &to))) {
                LOG_ERROR("...failed " << errno << " on ::localtime_r()");
            }
        } else {
            LOG_DEBUG("::gmtime_r(&from, &to)...");
            if (!(t = ::gmtime_r(&from, &to))) {
                LOG_ERROR("...failed " << errno << " on ::gmtime_r()");
            }
        }
        return t;
    }
    virtual time_t* from_system_time
    (time_t& to, const struct tm& from, bool is_local = false) const {
        struct tm tm = from;
        if ((is_local)) {
            LOG_DEBUG("::mktime(&tm)...");
            if (0 > (to = ::mktime(&tm))) {
                LOG_ERROR("...failed " << errno << " on ::mktime()");
                return 0;
            }
        } else {
            LOG_DEBUG("::timegm(&tm)...");
            if (0 > (to = ::timegm(&tm))) {
                LOG_ERROR("...failed " << errno << " on ::timegm()");
                return 0;
            }
        }
        return &to;
    }

    virtual bool is_volume_directory_separator(char c) const {
        if (('\\' == c)) {
            return true;
        }
        return false;
    }
    virtual bool is_directory_separator(char c) const {
        if (('/' == c) || (is_volume_directory_separator(c))) {
            return true;
        }
        return false;
    }
    virtual const char& volume_directory_separator() const {
        static const char c = ((char)'\\');
        return c;
    }
    virtual const char& directory_separator() const {
        static const char c = ((char)'/');
        return c;
    }
    
protected:
    stat_t st_, lst_, to_st_;
    utimbuf_t ut_;
};
typedef entryt<> entry;

} /// namespace fs
} /// namespace posix
} /// namespace os
} /// namespace xos

#endif /// _XOS_OS_POSIX_FS_ENTRY_HPP 
