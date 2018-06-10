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
///   File: main.hpp
///
/// Author: $author$
///   Date: 4/24/2018
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_APP_CONSOLE_ARCHA_MAIN_HPP
#define _XOS_APP_CONSOLE_ARCHA_MAIN_HPP

#include "xos/app/console/archa/main_opt.hpp"
#include "xos/app/console/archa/branch.hpp"
#include "xos/fs/path.hpp"
#include "xos/os/fs/entry.hpp"
#include "xos/base/to_string.hpp"

namespace xos {
namespace app {
namespace console {
namespace archa {

typedef main_opt::implements maint_implements;
typedef main_opt maint_extends;
///////////////////////////////////////////////////////////////////////
///  Class: maint
///////////////////////////////////////////////////////////////////////
template 
<class TImplements = maint_implements, class TExtends = maint_extends>

class _EXPORT_CLASS maint: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;
    typedef maint derives;

    typedef typename implements::string_t string_t;
    typedef typename implements::char_t char_t;
    typedef typename implements::end_char_t end_char_t;
    enum { end_char = implements::end_char };

    maint() {
    }
    virtual ~maint() {
    }
private:
    maint(const maint &copy) {
    }
    
public:
    virtual leaf* found(leaf* l) {
        entry* e = l;
        found(e);
        return 0;
    }
    virtual branch* found(branch* b) {
        entry* e = b;
        found(e);
        for (auto l: b->leaves()) {
            found(l);
        }
        return 0;
    }
    virtual entry* found(entry* b) {
        typedef entry::char_t char_t;
        if (b) {
            size_t length = 0;
            const char_t *chars = b->path_name(),
                         *separator_chars = b->directory_separator_chars(),
                         *name_chars = b->name();
            string_t path(chars);
            if ((name_chars[0])) {
                if ((chars) && (chars[length-1]!=separator_chars[0])) {
                    path.append(separator_chars);
                }
                path.append(name_chars);
            }
            if ((chars = path.has_chars())) {
                this->outln(path.chars());
            }
        }
        return 0;
    }

protected:
    virtual int run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        const char* chars = 0;//(optind < argc)?(argv[optind]):(argv[0]);
        /*fs::path p(chars);
        err = path(p);*/
        if ((optind<argc) && (argv)) {
            chars = argv[optind];
        }
        if ((chars) && (chars[0])) {
            err = path(chars);
        } else {
            err = this->usage(argc, argv, env);
        }
        return err;
    }
    /*int (derives::*path_)(fs::path& path);
    int path(fs::path& path) {
        int err = 0;
        if ((path_)) {
            err = (this->*path_)(path);
        } else {
            err = path_search(path);
        }
        return err;
    }
    int path_search(fs::path& path) {
        int err = 0;
        if ((path.has_chars())) {
            branch b(path.directory(), path.file_name(), fs::entry_type_directory);
            search(b);
        }
        return err;
    }
*/
    int (derives::*path_)(const char_t* path);
    int path(const char_t* path) {
        int err = 0;
        if ((path_)) {
            err = (this->*path_)(path);
        } else {
            err = path_search(path);
        }
        return err;
    }
    int path_search(const char_t* path) {
        int err = 0;
        if ((path) && (path[0])) {
            branch b(path);
            search(b);
        }
        return err;
    }
    int (derives::*search_)(branch& b);
    virtual int search(branch& b) {
        int err = 0;
        if ((search_)) {
            err = (this->*search_)(b);
        } else {
            err = all_search(b);
        }
        return err;
    }
    virtual int all_search(branch& b) {
        int err = 0;
        if (!(err = breadth_first_search(b))) {
            this ->outln();
            if (!(err = depth_first_search(b))) {
                this ->outln();
                if (!(err = depend_first_search(b))) {
                    this ->outln();
                    if (!(err = bottom_first_search(b))) {
                    }
                }
            }
        }
        return err;
    }
    virtual int breadth_first_search(branch& b) {
        int err = 0;
        std::tree::findt<branch, std::tree::breadth_first_searcht<branch, branches, leaves>, maint> search(*this, b);
        return err;
    }
    virtual int depth_first_search(branch& b) {
        int err = 0;
        std::tree::findt<branch, std::tree::depth_first_searcht<branch, branches, leaves>, maint> search(*this, b);
        return err;
    }
    virtual int depend_first_search(branch& b) {
        int err = 0;
        std::tree::findt<branch, std::tree::depend_first_searcht<branch, branches, leaves>, maint> search(*this, b);
        return err;
    }
    virtual int bottom_first_search(branch& b) {
        int err = 0;
        std::tree::findt<branch, std::tree::bottom_first_searcht<branch, branches, leaves>, maint> search(*this, b);
        return err;
    }
    /*virtual int path_stat(fs::path& path) {
        int err = 0;
        os::os::fs::entry entry;
        fs::entry_type type;

        if ((type = entry.exists(path))) {
            const fs::time* time  = 0;
            
            this->outlln("path = \"", entry.path(), "\"", NULL);
            this->outlln("name = \"", entry.name(), "\"", NULL);
            this->outlln("type = ", type.name(), NULL);
            for (fs::time_when_which when = fs::first_time_when; 
                 when < fs::next_time_when; when = fs::time_when::next(when)) {
                
                if ((time = entry.has_time_when(when))) {
                    unsigned_to_string year(time->year()), 
                                       month(time->month()), 
                                       day(time->day());
                    
                    this->outlln
                    ("time ", time->when_name(), " = ", 
                     month.chars(), "/", day.chars(), "/", year.chars(), NULL);
                }
            }
        }
        return err;
    }*/
    int path_stat(const char_t* path) {
        int err = 0;
        return err;
    }

    virtual int on_stat_option
    (int optval, const char_t* optarg,
     const char_t* optname, int optind,
     int argc, char_t**argv, char_t**env) {
        int err = 0;
        path_ = &derives::path_stat;
        return err;
    }
    virtual int on_search_option
    (int optval, const char_t* optarg,
     const char_t* optname, int optind,
     int argc, char_t**argv, char_t**env) {
        int err = 0;
        path_ = &derives::path_search;
        if ((optarg) && (optarg[0])) {
            if (((!optarg[1]) && (optarg[0]==(XOS_CONSOLE_ARCHA_MAIN_SEARCH_OPTARG_BREADTH[1])))
                || (!chars_t::compare(optarg, XOS_CONSOLE_ARCHA_MAIN_SEARCH_OPTARG_BREADTH))) {
                search_ = &derives::breadth_first_search;
            } else {
                if (((!optarg[1]) && (optarg[0]==(XOS_CONSOLE_ARCHA_MAIN_SEARCH_OPTARG_DEPTH[1])))
                    || (!chars_t::compare(optarg, XOS_CONSOLE_ARCHA_MAIN_SEARCH_OPTARG_DEPTH))) {
                    search_ = &derives::depth_first_search;
                } else {
                    if (((!optarg[1]) && (optarg[0]==(XOS_CONSOLE_ARCHA_MAIN_SEARCH_OPTARG_DEPEND[1])))
                        || (!chars_t::compare(optarg, XOS_CONSOLE_ARCHA_MAIN_SEARCH_OPTARG_DEPEND))) {
                        search_ = &derives::depend_first_search;
                    } else {
                        err = this->on_invalid_option_arg
                        (optval, optarg, optname, optind, argc, argv, env);
                    }
                }
            }
        }
        return err;
    }
};
typedef maint<> main;

} /// namespace archa
} /// namespace console
} /// namespace app
} /// namespace xos

#endif /// _XOS_APP_CONSOLE_ARCHA_MAIN_HPP 
