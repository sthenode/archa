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
///   File: branch.hpp
///
/// Author: $author$
///   Date: 4/29/2018
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_APP_CONSOLE_ARCHA_BRANCH_HPP
#define _XOS_APP_CONSOLE_ARCHA_BRANCH_HPP

#include "xos/base/std/tree/search.hpp"
#include "xos/os/fs/directory/entry.hpp"
#include "xos/os/fs/directory/path.hpp"

namespace xos {
namespace app {
namespace console {
namespace archa {

class branch;
typedef fs::directory::entry entry;
typedef std::tree::leaft<branch, entry> leaf_extends;
///////////////////////////////////////////////////////////////////////
///  Class: leaf
///////////////////////////////////////////////////////////////////////
class leaf: public leaf_extends {
public:
    typedef leaf_extends extends;
    leaf(const string_t& path, const string_t& name, fs::entry_type type) {
        construct(path.chars(), name.chars(), type);
    }
    leaf(const string_t& path, const fs::directory::entry& entry) {
        construct(path.chars(), entry);
    }
    leaf(const char* path, const char* name, fs::entry_type type) {
        construct(path, name, type);
    }
    leaf(const char* path, const fs::directory::entry& entry) {
        construct(path, entry);
    }
    leaf(const fs::directory::entry& entry) {
        construct(entry);
    }
    leaf(const leaf& copy) {
        construct(copy);
    }
    leaf() {
        construct();
    }
    void construct(const char* path, const char* name, fs::entry_type type) {
        construct();
        this->set_path_name(path);
        this->set_name(name);
        this->set_type(type);
    }
    void construct(const char* path, const fs::directory::entry& entry) {
        construct(entry);
        this->set_path_name(path);
    }
    void construct(const fs::directory::entry& entry) {
        extends::construct(entry);
        construct();
    }
    void construct() {
    }
    virtual ~leaf() {}
};

typedef std::tree::leavest<leaf> leaves;
typedef std::tree::branchest<branch> branches;
typedef std::tree::brancht<branch, branches, leaves, entry> branch_extends;
///////////////////////////////////////////////////////////////////////
///  Class: branch
///////////////////////////////////////////////////////////////////////
class branch: public branch_extends {
public:
    typedef branch_extends extends;

    branch(const string_t& path, const string_t& name, fs::entry_type type) {
        construct(path.chars(), name.chars(), type);
    }
    branch(const string_t& path, const fs::directory::entry& entry) {
        construct(path.chars(), entry);
    }
    branch(const char* path, const char* name, fs::entry_type type) {
        construct(path, name, type);
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
        construct();
    }
    virtual ~branch() {}

    void construct(const char* path, const char* name, fs::entry_type type) {
        construct();
        this->set_path_name(path);
        this->set_name(name);
        this->set_type(type);
    }
    void construct(const char* path, const fs::directory::entry& entry) {
        construct(entry);
        this->set_path_name(path);
    }
    void construct(const fs::directory::entry& entry) {
        extends::construct(entry);
        construct();
    }
    void construct() {
        got_branches_=(false);
    }

    virtual archa::leaves& leaves() const {
        get_branches();
        return extends::leaves();
    }
    virtual archa::branches& branches() const {
        get_branches();
        return extends::branches();
    }
    virtual archa::branches& get_branches() const {
        archa::branches& branches = extends::branches();
        archa::leaves& leaves = extends::leaves();
        bool& got_branches = this->got_branches();

        if (!(got_branches)) {
            const char_t* chars = 0;
            size_t length = 0;

            got_branches=(true);
            if ((fs::entry_type_directory == (this->type())) && (!this->is_circular())) {
                const char_t* directory_separator_chars = 0;
                string_t name(this->path_name());

                if ((chars = name.has_chars(length))) {
                    if ((directory_separator_chars = this->directory_separator_chars()) 
                         && (chars[length-1] != directory_separator_chars[0])) {
                        name.append(directory_separator_chars);
                    }
                }
                if ((chars = this->name(length))) {
                    os::os::fs::directory::path path;

                    name.append(chars, length);
                    LOG_DEBUG("path.open(name = \"" << name << "\")...");
                    if ((path.open(name))) {
                        os::os::fs::directory::entry* entry = 0;

                        if ((entry = path.get_first_entry())) {
                            branch* b = 0;
                            leaf* l = 0;
                            do {
                                if ((fs::entry_type_directory == (entry->type())) && (!entry->is_circular())) {
                                    LOG_DEBUG("new branch(name = \"" << name << "\", *entry)...")
                                    if ((b = new branch(name, *entry))) {
                                        branches.push_back(b);
                                    } else {
                                        LOG_ERROR("...failed on new branch(name = \"" << name << "\", *entry)");
                                        break;
                                    }
                                } else {
                                    if (fs::entry_type_directory != (entry->type())) {
                                        LOG_DEBUG("new leaf(name = \"" << name << "\", *entry)...")
                                        if ((l = new leaf(name, *entry))) {
                                            leaves.push_back(l);
                                        } else {
                                            LOG_ERROR("...failed on new leaf(name = \"" << name << "\", *entry)");
                                            break;
                                        }
                                    }
                                }
                                entry = path.get_next_entry();
                            } while ((entry));
                        }
                        path.close();
                    } else {
                        LOG_ERROR("...failed on path.open(name = \"" << name << "\")");
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

} /// namespace archa
} /// namespace console
} /// namespace app
} /// namespace xos

#endif /// _XOS_APP_CONSOLE_ARCHA_BRANCH_HPP 
