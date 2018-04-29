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

#include "xos/console/getopt/main.hpp"
#include "xos/fs/entry.hpp"
#include "xos/fs/path.hpp"
#include "xos/fs/directory/entry.hpp"
#include "xos/fs/directory/path.hpp"
#include "xos/os/fs/entry.hpp"
#include "xos/os/fs/path.hpp"
#include "xos/os/fs/directory/entry.hpp"
#include "xos/os/fs/directory/path.hpp"
#include "xos/base/to_string.hpp"
#include "xos/base/std/tree/search.hpp"

namespace xos {
namespace app {
namespace console {
namespace archa {

class branch;
typedef std::tree::branchest<branch> branches;
typedef std::tree::brancht<branch, branches, fs::directory::entry> branch_extends;
///////////////////////////////////////////////////////////////////////
///  Class: branch
///////////////////////////////////////////////////////////////////////
class branch: public branch_extends {
public:
    typedef branch_extends extends;
    branch(const char* path, const char* name, fs::entry_type type) {
        this->set_path_name(path);
        this->set_name(name);
        this->set_type(type);
    }
    branch(const char* path, const fs::directory::entry& entry) {
        construct(path, entry);
    }
    branch(const fs::directory::entry& entry) {
        construct(entry);
    }
    branch(const branch& copy) {
        construct(copy);
    }
    branch() {
    }
    void construct(const char* path, const fs::directory::entry& entry) {
        construct(entry);
        this->set_path_name(path);
    }
    void construct(const fs::directory::entry& entry) {
        extends::construct(entry);
        got_branches_=(false);
    }
    virtual ~branch() {
    }
    virtual archa::branches& branches() const {
        archa::branches& branches = extends::branches();
        bool& got_branches = this->got_branches();

        if (!(got_branches)) {
            const char_t* chars = 0;

            got_branches=(true);
            if ((fs::entry_type_directory == (this->type())) 
                && (!this->is_circular()) && (chars = this->path_name().has_chars())) {
                string_t name(chars);

                name.append(this->directory_separator_chars());
                if ((chars = this->name())) {
                    os::os::fs::directory::path path;

                    name.append(chars);
                    if ((path.open(name))) {
                        os::os::fs::directory::entry* entry = 0;

                        if ((entry = path.get_first_entry())) {
                            do {
                                if (!(entry->is_circular())) {
                                    branches.push_back(new branch(name.chars(),*entry));
                                }
                                entry = path.get_next_entry();
                            } while ((entry));
                        }
                        path.close();
                    } else {
                    }
                }
            }
        }
        return branches;
    }
    virtual bool& got_branches() const {
        return (bool&)got_branches_;
    }
protected:
    bool got_branches_;
};

typedef xos::console::getopt::main::implements maint_implements;
typedef xos::console::getopt::main maint_extends;
///////////////////////////////////////////////////////////////////////
///  Class: maint
///////////////////////////////////////////////////////////////////////
template 
<class TImplements = maint_implements, class TExtends = maint_extends>

class _EXPORT_CLASS maint: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;

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
    virtual branch* found(branch* b) {
        typedef branch::char_t char_t;
        if (b) {
            size_t length = 0;
            const char_t *chars = b->path_name().has_chars(length),
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
    typedef std::tree::findt<branch, std::tree::depth_first_searcht<branch, branches>, maint> depth_first_search;
    
    virtual int run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        const char* chars = (optind < argc)?(argv[optind]):(argv[0]);
        fs::path path(chars);
        this->outlln("path = \"", path.directory().chars(), "\"", NULL);
        this->outlln("name = \"", path.file_name().chars(), "\"", NULL);
        if ((chars = path.has_chars())) {
            branch dir(path.directory().chars(), path.file_name().chars(), fs::entry_type_directory);
            depth_first_search search(*this, dir);
        }
        return err;
    }
    virtual int run_list(int argc, char_t** argv, char_t** env) {
        int err = 0;
        const char* chars = (optind < argc)?(argv[optind]):(argv[0]);
        os::os::fs::directory::path path;
        
        if ((path.open(chars))) {
            err = on_open(path);
            path.close();
        }
        return err;
    }
    virtual int on_open(os::os::fs::directory::path& path) {
        int err = 0;
        os::os::fs::directory::entry* entry = 0;
        if ((entry = path.get_first_entry())) {
            string_t name;
            do {
                if (!(entry->is_circular())) {
                    name.assignl(path.name(), path.directory_separator_chars(), entry->name(), NULL);
                    this->outlln("name = \"", name.chars(), "\"", NULL);
                }
            } while ((entry = path.get_next_entry()));
        }
        return err;
    }
    virtual int run_stat(int argc, char_t** argv, char_t** env) {
        int err = 0;
        const char* chars = (optind < argc)?(argv[optind]):(argv[0]);
        fs::path path(chars);
        os::os::fs::entry entry;
        fs::entry_type type;

        if ((chars = path.has_chars())) {
            this->outlln("path = \"", chars, "\"", NULL);
        }
        if ((chars = path.host().has_chars())) {
            this->outlln("host = \"", chars, "\"", NULL);
        }
        if ((chars = path.volume().has_chars())) {
            this->outlln("volume = \"", chars, "\"", NULL);
        }
        if ((chars = path.directory().has_chars())) {
            this->outlln("directory = \"", chars, "\"", NULL);
        }
        if ((chars = path.file_name().has_chars())) {
            this->outlln("name = \"", chars, "\"", NULL);
        }
        if ((chars = path.file_base().has_chars())) {
            this->outlln("base = \"", chars, "\"", NULL);
        }
        if ((chars = path.file_extension().has_chars())) {
            this->outlln("extension = \"", chars, "\"", NULL);
        }

        if ((type = entry.exists(path))) {
            const fs::time* time  = 0;
            
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
    }
};
typedef maint<> main;

} /// namespace archa
} /// namespace console
} /// namespace app
} /// namespace xos

#endif /// _XOS_APP_CONSOLE_ARCHA_MAIN_HPP 
