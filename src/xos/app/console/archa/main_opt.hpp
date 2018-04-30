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
///   File: main_opt.hpp
///
/// Author: $author$
///   Date: 4/30/2018
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_APP_CONSOLE_ARCHA_MAIN_OPT_HPP
#define _XOS_APP_CONSOLE_ARCHA_MAIN_OPT_HPP

#include "xos/console/getopt/main.hpp"

#define XOS_CONSOLE_ARCHA_MAIN_STAT_OPT "stat"
#define XOS_CONSOLE_ARCHA_MAIN_STAT_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_NONE
#define XOS_CONSOLE_ARCHA_MAIN_STAT_OPTARG_RESULT 0
#define XOS_CONSOLE_ARCHA_MAIN_STAT_OPTARG ""
#define XOS_CONSOLE_ARCHA_MAIN_STAT_OPTUSE "stat [source]"
#define XOS_CONSOLE_ARCHA_MAIN_STAT_OPTVAL_S "a"
#define XOS_CONSOLE_ARCHA_MAIN_STAT_OPTVAL_C 'a'
#define XOS_CONSOLE_ARCHA_MAIN_STAT_OPTION \
   {XOS_CONSOLE_ARCHA_MAIN_STAT_OPT, \
    XOS_CONSOLE_ARCHA_MAIN_STAT_OPTARG_REQUIRED, \
    XOS_CONSOLE_ARCHA_MAIN_STAT_OPTARG_RESULT, \
    XOS_CONSOLE_ARCHA_MAIN_STAT_OPTVAL_C}, \

#define XOS_CONSOLE_ARCHA_MAIN_SEARCH_OPT "search"
#define XOS_CONSOLE_ARCHA_MAIN_SEARCH_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_REQUIRED
#define XOS_CONSOLE_ARCHA_MAIN_SEARCH_OPTARG_RESULT 0
#define XOS_CONSOLE_ARCHA_MAIN_SEARCH_OPTARG_BREADTH "(b)breadth-first"
#define XOS_CONSOLE_ARCHA_MAIN_SEARCH_OPTARG_DEPTH "(d)depth-first"
#define XOS_CONSOLE_ARCHA_MAIN_SEARCH_OPTARG_DEPEND "(p)depend-first"
#define XOS_CONSOLE_ARCHA_MAIN_SEARCH_OPTARG \
    "{ " XOS_CONSOLE_ARCHA_MAIN_SEARCH_OPTARG_BREADTH \
    " | " XOS_CONSOLE_ARCHA_MAIN_SEARCH_OPTARG_DEPTH \
    " | " XOS_CONSOLE_ARCHA_MAIN_SEARCH_OPTARG_DEPEND " }"
#define XOS_CONSOLE_ARCHA_MAIN_SEARCH_OPTUSE ""
#define XOS_CONSOLE_ARCHA_MAIN_SEARCH_OPTVAL_S "h:"
#define XOS_CONSOLE_ARCHA_MAIN_SEARCH_OPTVAL_C 'h'
#define XOS_CONSOLE_ARCHA_MAIN_SEARCH_OPTION \
   {XOS_CONSOLE_ARCHA_MAIN_SEARCH_OPT, \
    XOS_CONSOLE_ARCHA_MAIN_SEARCH_OPTARG_REQUIRED, \
    XOS_CONSOLE_ARCHA_MAIN_SEARCH_OPTARG_RESULT, \
    XOS_CONSOLE_ARCHA_MAIN_SEARCH_OPTVAL_C}, \

#define XOS_CONSOLE_ARCHA_MAIN_RECURSIVE_OPT "recursive"
#define XOS_CONSOLE_ARCHA_MAIN_RECURSIVE_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_NONE
#define XOS_CONSOLE_ARCHA_MAIN_RECURSIVE_OPTARG_RESULT 0
#define XOS_CONSOLE_ARCHA_MAIN_RECURSIVE_OPTARG ""
#define XOS_CONSOLE_ARCHA_MAIN_RECURSIVE_OPTUSE "search [source] recursively"
#define XOS_CONSOLE_ARCHA_MAIN_RECURSIVE_OPTVAL_S "r"
#define XOS_CONSOLE_ARCHA_MAIN_RECURSIVE_OPTVAL_C 'r'
#define XOS_CONSOLE_ARCHA_MAIN_RECURSIVE_OPTION \
   {XOS_CONSOLE_ARCHA_MAIN_RECURSIVE_OPT, \
    XOS_CONSOLE_ARCHA_MAIN_RECURSIVE_OPTARG_REQUIRED, \
    XOS_CONSOLE_ARCHA_MAIN_RECURSIVE_OPTARG_RESULT, \
    XOS_CONSOLE_ARCHA_MAIN_RECURSIVE_OPTVAL_C}, \

#define XOS_CONSOLE_ARCHA_MAIN_REFLECTIVE_OPT "reflective"
#define XOS_CONSOLE_ARCHA_MAIN_REFLECTIVE_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_NONE
#define XOS_CONSOLE_ARCHA_MAIN_REFLECTIVE_OPTARG_RESULT 0
#define XOS_CONSOLE_ARCHA_MAIN_REFLECTIVE_OPTARG ""
#define XOS_CONSOLE_ARCHA_MAIN_REFLECTIVE_OPTUSE "reflect [source] entries in [target]"
#define XOS_CONSOLE_ARCHA_MAIN_REFLECTIVE_OPTVAL_S "f"
#define XOS_CONSOLE_ARCHA_MAIN_REFLECTIVE_OPTVAL_C 'f'
#define XOS_CONSOLE_ARCHA_MAIN_REFLECTIVE_OPTION \
   {XOS_CONSOLE_ARCHA_MAIN_REFLECTIVE_OPT, \
    XOS_CONSOLE_ARCHA_MAIN_REFLECTIVE_OPTARG_REQUIRED, \
    XOS_CONSOLE_ARCHA_MAIN_REFLECTIVE_OPTARG_RESULT, \
    XOS_CONSOLE_ARCHA_MAIN_REFLECTIVE_OPTVAL_C}, \

#define XOS_CONSOLE_ARCHA_MAIN_SOURCE_OPT "source"
#define XOS_CONSOLE_ARCHA_MAIN_SOURCE_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_NONE
#define XOS_CONSOLE_ARCHA_MAIN_SOURCE_OPTARG_RESULT 0
#define XOS_CONSOLE_ARCHA_MAIN_SOURCE_OPTARG ""
#define XOS_CONSOLE_ARCHA_MAIN_SOURCE_OPTUSE "output [source] entries"
#define XOS_CONSOLE_ARCHA_MAIN_SOURCE_OPTVAL_S "s"
#define XOS_CONSOLE_ARCHA_MAIN_SOURCE_OPTVAL_C 's'
#define XOS_CONSOLE_ARCHA_MAIN_SOURCE_OPTION \
   {XOS_CONSOLE_ARCHA_MAIN_SOURCE_OPT, \
    XOS_CONSOLE_ARCHA_MAIN_SOURCE_OPTARG_REQUIRED, \
    XOS_CONSOLE_ARCHA_MAIN_SOURCE_OPTARG_RESULT, \
    XOS_CONSOLE_ARCHA_MAIN_SOURCE_OPTVAL_C}, \

#define XOS_CONSOLE_ARCHA_MAIN_TARGET_OPT "target"
#define XOS_CONSOLE_ARCHA_MAIN_TARGET_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_NONE
#define XOS_CONSOLE_ARCHA_MAIN_TARGET_OPTARG_RESULT 0
#define XOS_CONSOLE_ARCHA_MAIN_TARGET_OPTARG ""
#define XOS_CONSOLE_ARCHA_MAIN_TARGET_OPTUSE "output [target] entries"
#define XOS_CONSOLE_ARCHA_MAIN_TARGET_OPTVAL_S "t"
#define XOS_CONSOLE_ARCHA_MAIN_TARGET_OPTVAL_C 't'
#define XOS_CONSOLE_ARCHA_MAIN_TARGET_OPTION \
   {XOS_CONSOLE_ARCHA_MAIN_TARGET_OPT, \
    XOS_CONSOLE_ARCHA_MAIN_TARGET_OPTARG_REQUIRED, \
    XOS_CONSOLE_ARCHA_MAIN_TARGET_OPTARG_RESULT, \
    XOS_CONSOLE_ARCHA_MAIN_TARGET_OPTVAL_C}, \

#define XOS_CONSOLE_ARCHA_MAIN_REVERSE_OPT "reverse"
#define XOS_CONSOLE_ARCHA_MAIN_REVERSE_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_NONE
#define XOS_CONSOLE_ARCHA_MAIN_REVERSE_OPTARG_RESULT 0
#define XOS_CONSOLE_ARCHA_MAIN_REVERSE_OPTARG ""
#define XOS_CONSOLE_ARCHA_MAIN_REVERSE_OPTUSE "reflect [target] entries in [source]"
#define XOS_CONSOLE_ARCHA_MAIN_REVERSE_OPTVAL_S "v"
#define XOS_CONSOLE_ARCHA_MAIN_REVERSE_OPTVAL_C 'v'
#define XOS_CONSOLE_ARCHA_MAIN_REVERSE_OPTION \
   {XOS_CONSOLE_ARCHA_MAIN_REVERSE_OPT, \
    XOS_CONSOLE_ARCHA_MAIN_REVERSE_OPTARG_REQUIRED, \
    XOS_CONSOLE_ARCHA_MAIN_REVERSE_OPTARG_RESULT, \
    XOS_CONSOLE_ARCHA_MAIN_REVERSE_OPTVAL_C}, \

#define XOS_CONSOLE_ARCHA_MAIN_MATCH_OPT "match"
#define XOS_CONSOLE_ARCHA_MAIN_MATCH_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_REQUIRED
#define XOS_CONSOLE_ARCHA_MAIN_MATCH_OPTARG_RESULT 0
#define XOS_CONSOLE_ARCHA_MAIN_MATCH_OPTARG "<patterns> { * | *.* | n.* | *.n | n* | *n | n },..."
#define XOS_CONSOLE_ARCHA_MAIN_MATCH_OPTUSE "include entry <patterns>"
#define XOS_CONSOLE_ARCHA_MAIN_MATCH_OPTVAL_S "m:"
#define XOS_CONSOLE_ARCHA_MAIN_MATCH_OPTVAL_C 'm'
#define XOS_CONSOLE_ARCHA_MAIN_MATCH_OPTION \
   {XOS_CONSOLE_ARCHA_MAIN_MATCH_OPT, \
    XOS_CONSOLE_ARCHA_MAIN_MATCH_OPTARG_REQUIRED, \
    XOS_CONSOLE_ARCHA_MAIN_MATCH_OPTARG_RESULT, \
    XOS_CONSOLE_ARCHA_MAIN_MATCH_OPTVAL_C}, \

#define XOS_CONSOLE_ARCHA_MAIN_SKIP_OPT "skip"
#define XOS_CONSOLE_ARCHA_MAIN_SKIP_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_REQUIRED
#define XOS_CONSOLE_ARCHA_MAIN_SKIP_OPTARG_RESULT 0
#define XOS_CONSOLE_ARCHA_MAIN_SKIP_OPTARG "<patterns>"
#define XOS_CONSOLE_ARCHA_MAIN_SKIP_OPTUSE "skip entry <patterns>"
#define XOS_CONSOLE_ARCHA_MAIN_SKIP_OPTVAL_S "k:"
#define XOS_CONSOLE_ARCHA_MAIN_SKIP_OPTVAL_C 'k'
#define XOS_CONSOLE_ARCHA_MAIN_SKIP_OPTION \
   {XOS_CONSOLE_ARCHA_MAIN_SKIP_OPT, \
    XOS_CONSOLE_ARCHA_MAIN_SKIP_OPTARG_REQUIRED, \
    XOS_CONSOLE_ARCHA_MAIN_SKIP_OPTARG_RESULT, \
    XOS_CONSOLE_ARCHA_MAIN_SKIP_OPTVAL_C}, \

#define XOS_CONSOLE_ARCHA_MAIN_NEWER_OPT "newer"
#define XOS_CONSOLE_ARCHA_MAIN_NEWER_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_NONE
#define XOS_CONSOLE_ARCHA_MAIN_NEWER_OPTARG_RESULT 0
#define XOS_CONSOLE_ARCHA_MAIN_NEWER_OPTARG ""
#define XOS_CONSOLE_ARCHA_MAIN_NEWER_OPTUSE "include newer entries"
#define XOS_CONSOLE_ARCHA_MAIN_NEWER_OPTVAL_S "n"
#define XOS_CONSOLE_ARCHA_MAIN_NEWER_OPTVAL_C 'n'
#define XOS_CONSOLE_ARCHA_MAIN_NEWER_OPTION \
   {XOS_CONSOLE_ARCHA_MAIN_NEWER_OPT, \
    XOS_CONSOLE_ARCHA_MAIN_NEWER_OPTARG_REQUIRED, \
    XOS_CONSOLE_ARCHA_MAIN_NEWER_OPTARG_RESULT, \
    XOS_CONSOLE_ARCHA_MAIN_NEWER_OPTVAL_C}, \

#define XOS_CONSOLE_ARCHA_MAIN_OLDER_OPT "older"
#define XOS_CONSOLE_ARCHA_MAIN_OLDER_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_NONE
#define XOS_CONSOLE_ARCHA_MAIN_OLDER_OPTARG_RESULT 0
#define XOS_CONSOLE_ARCHA_MAIN_OLDER_OPTARG ""
#define XOS_CONSOLE_ARCHA_MAIN_OLDER_OPTUSE "include older entries"
#define XOS_CONSOLE_ARCHA_MAIN_OLDER_OPTVAL_S "o"
#define XOS_CONSOLE_ARCHA_MAIN_OLDER_OPTVAL_C 'o'
#define XOS_CONSOLE_ARCHA_MAIN_OLDER_OPTION \
   {XOS_CONSOLE_ARCHA_MAIN_OLDER_OPT, \
    XOS_CONSOLE_ARCHA_MAIN_OLDER_OPTARG_REQUIRED, \
    XOS_CONSOLE_ARCHA_MAIN_OLDER_OPTARG_RESULT, \
    XOS_CONSOLE_ARCHA_MAIN_OLDER_OPTVAL_C}, \

#define XOS_CONSOLE_ARCHA_MAIN_ALL_OPT "all"
#define XOS_CONSOLE_ARCHA_MAIN_ALL_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_NONE
#define XOS_CONSOLE_ARCHA_MAIN_ALL_OPTARG_RESULT 0
#define XOS_CONSOLE_ARCHA_MAIN_ALL_OPTARG ""
#define XOS_CONSOLE_ARCHA_MAIN_ALL_OPTUSE "include all entries"
#define XOS_CONSOLE_ARCHA_MAIN_ALL_OPTVAL_S "l"
#define XOS_CONSOLE_ARCHA_MAIN_ALL_OPTVAL_C 'l'
#define XOS_CONSOLE_ARCHA_MAIN_ALL_OPTION \
   {XOS_CONSOLE_ARCHA_MAIN_ALL_OPT, \
    XOS_CONSOLE_ARCHA_MAIN_ALL_OPTARG_REQUIRED, \
    XOS_CONSOLE_ARCHA_MAIN_ALL_OPTARG_RESULT, \
    XOS_CONSOLE_ARCHA_MAIN_ALL_OPTVAL_C}, \

#define XOS_CONSOLE_ARCHA_MAIN_COMPARE_OPT "compare"
#define XOS_CONSOLE_ARCHA_MAIN_COMPARE_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_NONE
#define XOS_CONSOLE_ARCHA_MAIN_COMPARE_OPTARG_RESULT 0
#define XOS_CONSOLE_ARCHA_MAIN_COMPARE_OPTARG ""
#define XOS_CONSOLE_ARCHA_MAIN_COMPARE_OPTUSE "compare entries"
#define XOS_CONSOLE_ARCHA_MAIN_COMPARE_OPTVAL_S "c"
#define XOS_CONSOLE_ARCHA_MAIN_COMPARE_OPTVAL_C 'c'
#define XOS_CONSOLE_ARCHA_MAIN_COMPARE_OPTION \
   {XOS_CONSOLE_ARCHA_MAIN_COMPARE_OPT, \
    XOS_CONSOLE_ARCHA_MAIN_COMPARE_OPTARG_REQUIRED, \
    XOS_CONSOLE_ARCHA_MAIN_COMPARE_OPTARG_RESULT, \
    XOS_CONSOLE_ARCHA_MAIN_COMPARE_OPTVAL_C}, \

#define ARCHA_CONSOLE_MAIN_OPTIONS_CHARS \
    XOS_CONSOLE_ARCHA_MAIN_STAT_OPTVAL_S \
    XOS_CONSOLE_ARCHA_MAIN_SEARCH_OPTVAL_S \
    XOS_CONSOLE_ARCHA_MAIN_RECURSIVE_OPTVAL_S \
    XOS_CONSOLE_ARCHA_MAIN_REFLECTIVE_OPTVAL_S \
    XOS_CONSOLE_ARCHA_MAIN_SOURCE_OPTVAL_S \
    XOS_CONSOLE_ARCHA_MAIN_TARGET_OPTVAL_S \
    XOS_CONSOLE_ARCHA_MAIN_REVERSE_OPTVAL_S \
    XOS_CONSOLE_ARCHA_MAIN_MATCH_OPTVAL_S \
    XOS_CONSOLE_ARCHA_MAIN_SKIP_OPTVAL_S \
    XOS_CONSOLE_ARCHA_MAIN_NEWER_OPTVAL_S \
    XOS_CONSOLE_ARCHA_MAIN_OLDER_OPTVAL_S \
    XOS_CONSOLE_ARCHA_MAIN_ALL_OPTVAL_S \
    XOS_CONSOLE_ARCHA_MAIN_COMPARE_OPTVAL_S \
    XOS_CONSOLE_MAIN_DEBUG_OPTVAL_S \
    XOS_CONSOLE_MAIN_USAGE_OPTVAL_S

#define ARCHA_CONSOLE_MAIN_OPTIONS_OPTIONS \
    XOS_CONSOLE_ARCHA_MAIN_STAT_OPTION \
    XOS_CONSOLE_ARCHA_MAIN_SEARCH_OPTION \
    XOS_CONSOLE_ARCHA_MAIN_RECURSIVE_OPTION \
    XOS_CONSOLE_ARCHA_MAIN_REFLECTIVE_OPTION \
    XOS_CONSOLE_ARCHA_MAIN_SOURCE_OPTION \
    XOS_CONSOLE_ARCHA_MAIN_TARGET_OPTION \
    XOS_CONSOLE_ARCHA_MAIN_REVERSE_OPTION \
    XOS_CONSOLE_ARCHA_MAIN_MATCH_OPTION \
    XOS_CONSOLE_ARCHA_MAIN_SKIP_OPTION \
    XOS_CONSOLE_ARCHA_MAIN_NEWER_OPTION \
    XOS_CONSOLE_ARCHA_MAIN_OLDER_OPTION \
    XOS_CONSOLE_ARCHA_MAIN_ALL_OPTION \
    XOS_CONSOLE_ARCHA_MAIN_COMPARE_OPTION \
    XOS_CONSOLE_MAIN_DEBUG_OPTION \
    XOS_CONSOLE_MAIN_USAGE_OPTION

namespace xos {
namespace app {
namespace console {
namespace archa {

typedef xos::console::getopt::main::implements main_optt_implements;
typedef xos::console::getopt::main main_optt_extends;
///////////////////////////////////////////////////////////////////////
///  Class: main_optt
///////////////////////////////////////////////////////////////////////
template 
<class TImplements = main_optt_implements, class TExtends = main_optt_extends>

class _EXPORT_CLASS main_optt: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;
    typedef main_optt derives;

    typedef typename implements::string_t string_t;
    typedef typename implements::char_t char_t;
    typedef typename implements::end_char_t end_char_t;
    enum { end_char = implements::end_char };

    main_optt() {
    }
    virtual ~main_optt() {
    }
private:
    main_optt(const main_optt &copy) {
    }
    
    virtual int on_stat_option
    (int optval, const char_t* optarg,
     const char_t* optname, int optind,
     int argc, char_t**argv, char_t**env) {
        int err = 0;
        //if ((optarg) && (optarg[0])) {
        //}
        return err;
    }
    virtual int on_search_option
    (int optval, const char_t* optarg,
     const char_t* optname, int optind,
     int argc, char_t**argv, char_t**env) {
        int err = 0;
        //if ((optarg) && (optarg[0])) {
        //}
        return err;
    }
    virtual int on_recursive_option
    (int optval, const char_t* optarg,
     const char_t* optname, int optind,
     int argc, char_t**argv, char_t**env) {
        int err = 0;
        //if ((optarg) && (optarg[0])) {
        //}
        return err;
    }
    virtual int on_reflective_option
    (int optval, const char_t* optarg,
     const char_t* optname, int optind,
     int argc, char_t**argv, char_t**env) {
        int err = 0;
        //if ((optarg) && (optarg[0])) {
        //}
        return err;
    }
    virtual int on_source_option
    (int optval, const char_t* optarg,
     const char_t* optname, int optind,
     int argc, char_t**argv, char_t**env) {
        int err = 0;
        //if ((optarg) && (optarg[0])) {
        //}
        return err;
    }
    virtual int on_target_option
    (int optval, const char_t* optarg,
     const char_t* optname, int optind,
     int argc, char_t**argv, char_t**env) {
        int err = 0;
        //if ((optarg) && (optarg[0])) {
        //}
        return err;
    }
    virtual int on_reverse_option
    (int optval, const char_t* optarg,
     const char_t* optname, int optind,
     int argc, char_t**argv, char_t**env) {
        int err = 0;
        //if ((optarg) && (optarg[0])) {
        //}
        return err;
    }
    virtual int on_match_option
    (int optval, const char_t* optarg,
     const char_t* optname, int optind,
     int argc, char_t**argv, char_t**env) {
        int err = 0;
        //if ((optarg) && (optarg[0])) {
        //}
        return err;
    }
    virtual int on_skip_option
    (int optval, const char_t* optarg,
     const char_t* optname, int optind,
     int argc, char_t**argv, char_t**env) {
        int err = 0;
        //if ((optarg) && (optarg[0])) {
        //}
        return err;
    }
    virtual int on_newer_option
    (int optval, const char_t* optarg,
     const char_t* optname, int optind,
     int argc, char_t**argv, char_t**env) {
        int err = 0;
        //if ((optarg) && (optarg[0])) {
        //}
        return err;
    }
    virtual int on_older_option
    (int optval, const char_t* optarg,
     const char_t* optname, int optind,
     int argc, char_t**argv, char_t**env) {
        int err = 0;
        //if ((optarg) && (optarg[0])) {
        //}
        return err;
    }
    virtual int on_all_option
    (int optval, const char_t* optarg,
     const char_t* optname, int optind,
     int argc, char_t**argv, char_t**env) {
        int err = 0;
        //if ((optarg) && (optarg[0])) {
        //}
        return err;
    }
    virtual int on_compare_option
    (int optval, const char_t* optarg,
     const char_t* optname, int optind,
     int argc, char_t**argv, char_t**env) {
        int err = 0;
        //if ((optarg) && (optarg[0])) {
        //}
        return err;
    }

    virtual int on_option
    (int optval, const char_t* optarg,
     const char_t* optname, int optind,
     int argc, char_t**argv, char_t**env) {
        int err = 0;
        switch(optval) {
        case XOS_CONSOLE_ARCHA_MAIN_STAT_OPTVAL_C:
            err = on_stat_option
            (optval, optarg, optname, optind, argc, argv, env);
            break;
        case XOS_CONSOLE_ARCHA_MAIN_SEARCH_OPTVAL_C:
            err = on_search_option
            (optval, optarg, optname, optind, argc, argv, env);
            break;
        case XOS_CONSOLE_ARCHA_MAIN_RECURSIVE_OPTVAL_C:
            err = on_recursive_option
            (optval, optarg, optname, optind, argc, argv, env);
            break;
        case XOS_CONSOLE_ARCHA_MAIN_REFLECTIVE_OPTVAL_C:
            err = on_reflective_option
            (optval, optarg, optname, optind, argc, argv, env);
            break;
        case XOS_CONSOLE_ARCHA_MAIN_SOURCE_OPTVAL_C:
            err = on_source_option
            (optval, optarg, optname, optind, argc, argv, env);
            break;
        case XOS_CONSOLE_ARCHA_MAIN_TARGET_OPTVAL_C:
            err = on_target_option
            (optval, optarg, optname, optind, argc, argv, env);
            break;
        case XOS_CONSOLE_ARCHA_MAIN_REVERSE_OPTVAL_C:
            err = on_reverse_option
            (optval, optarg, optname, optind, argc, argv, env);
            break;
        case XOS_CONSOLE_ARCHA_MAIN_MATCH_OPTVAL_C:
            err = on_match_option
            (optval, optarg, optname, optind, argc, argv, env);
            break;
        case XOS_CONSOLE_ARCHA_MAIN_SKIP_OPTVAL_C:
            err = on_skip_option
            (optval, optarg, optname, optind, argc, argv, env);
            break;
        case XOS_CONSOLE_ARCHA_MAIN_NEWER_OPTVAL_C:
            err = on_newer_option
            (optval, optarg, optname, optind, argc, argv, env);
            break;
        case XOS_CONSOLE_ARCHA_MAIN_OLDER_OPTVAL_C:
            err = on_older_option
            (optval, optarg, optname, optind, argc, argv, env);
            break;
        case XOS_CONSOLE_ARCHA_MAIN_ALL_OPTVAL_C:
            err = on_all_option
            (optval, optarg, optname, optind, argc, argv, env);
            break;
        case XOS_CONSOLE_ARCHA_MAIN_COMPARE_OPTVAL_C:
            err = on_compare_option
            (optval, optarg, optname, optind, argc, argv, env);
            break;
        case XOS_CONSOLE_MAIN_DEBUG_OPTVAL_C:
            err = this->on_debug_option
            (optval, optarg, optname, optind, argc, argv, env);
            break;
        case XOS_CONSOLE_MAIN_USAGE_OPTVAL_C:
            err = this->on_usage_option
            (optval, optarg, optname, optind, argc, argv, env);
            break;
        default:
            err = extends::on_option
            (optval, optarg, optname, optind, argc, argv, env);
        }
        return err;
    }
    virtual const char_t* option_usage
    (const char_t*& optarg, const struct option* longopt) {
        const char_t* chars = "";
        switch(longopt->val) {
        case XOS_CONSOLE_ARCHA_MAIN_STAT_OPTVAL_C:
            optarg = XOS_CONSOLE_ARCHA_MAIN_STAT_OPTARG;
            chars = XOS_CONSOLE_ARCHA_MAIN_STAT_OPTUSE;
            break;
        case XOS_CONSOLE_ARCHA_MAIN_SEARCH_OPTVAL_C:
            optarg = XOS_CONSOLE_ARCHA_MAIN_SEARCH_OPTARG;
            chars = XOS_CONSOLE_ARCHA_MAIN_SEARCH_OPTUSE;
            break;
        case XOS_CONSOLE_ARCHA_MAIN_RECURSIVE_OPTVAL_C:
            optarg = XOS_CONSOLE_ARCHA_MAIN_RECURSIVE_OPTARG;
            chars = XOS_CONSOLE_ARCHA_MAIN_RECURSIVE_OPTUSE;
            break;
        case XOS_CONSOLE_ARCHA_MAIN_REFLECTIVE_OPTVAL_C:
            optarg = XOS_CONSOLE_ARCHA_MAIN_REFLECTIVE_OPTARG;
            chars = XOS_CONSOLE_ARCHA_MAIN_REFLECTIVE_OPTUSE;
            break;
        case XOS_CONSOLE_ARCHA_MAIN_SOURCE_OPTVAL_C:
            optarg = XOS_CONSOLE_ARCHA_MAIN_SOURCE_OPTARG;
            chars = XOS_CONSOLE_ARCHA_MAIN_SOURCE_OPTUSE;
            break;
        case XOS_CONSOLE_ARCHA_MAIN_TARGET_OPTVAL_C:
            optarg = XOS_CONSOLE_ARCHA_MAIN_TARGET_OPTARG;
            chars = XOS_CONSOLE_ARCHA_MAIN_TARGET_OPTUSE;
            break;
        case XOS_CONSOLE_ARCHA_MAIN_REVERSE_OPTVAL_C:
            optarg = XOS_CONSOLE_ARCHA_MAIN_REVERSE_OPTARG;
            chars = XOS_CONSOLE_ARCHA_MAIN_REVERSE_OPTUSE;
            break;
        case XOS_CONSOLE_ARCHA_MAIN_MATCH_OPTVAL_C:
            optarg = XOS_CONSOLE_ARCHA_MAIN_MATCH_OPTARG;
            chars = XOS_CONSOLE_ARCHA_MAIN_MATCH_OPTUSE;
            break;
        case XOS_CONSOLE_ARCHA_MAIN_SKIP_OPTVAL_C:
            optarg = XOS_CONSOLE_ARCHA_MAIN_SKIP_OPTARG;
            chars = XOS_CONSOLE_ARCHA_MAIN_SKIP_OPTUSE;
            break;
        case XOS_CONSOLE_ARCHA_MAIN_NEWER_OPTVAL_C:
            optarg = XOS_CONSOLE_ARCHA_MAIN_NEWER_OPTARG;
            chars = XOS_CONSOLE_ARCHA_MAIN_NEWER_OPTUSE;
            break;
        case XOS_CONSOLE_ARCHA_MAIN_OLDER_OPTVAL_C:
            optarg = XOS_CONSOLE_ARCHA_MAIN_OLDER_OPTARG;
            chars = XOS_CONSOLE_ARCHA_MAIN_OLDER_OPTUSE;
            break;
        case XOS_CONSOLE_ARCHA_MAIN_ALL_OPTVAL_C:
            optarg = XOS_CONSOLE_ARCHA_MAIN_ALL_OPTARG;
            chars = XOS_CONSOLE_ARCHA_MAIN_ALL_OPTUSE;
            break;
        case XOS_CONSOLE_ARCHA_MAIN_COMPARE_OPTVAL_C:
            optarg = XOS_CONSOLE_ARCHA_MAIN_COMPARE_OPTARG;
            chars = XOS_CONSOLE_ARCHA_MAIN_COMPARE_OPTUSE;
            break;
        case XOS_CONSOLE_MAIN_DEBUG_OPTVAL_C:
            chars = this->debug_option_usage(optarg, longopt);
            break;
        case XOS_CONSOLE_MAIN_USAGE_OPTVAL_C:
            chars = this->usage_option_usage(optarg, longopt);
            break;
        default:
            chars = extends::option_usage(optarg, longopt);
            break;
        }
        return chars;
    }
    virtual const char_t* options(const struct option*& longopts) {
        static const char_t* chars = ARCHA_CONSOLE_MAIN_OPTIONS_CHARS;
        static struct option optstruct[]= {
            ARCHA_CONSOLE_MAIN_OPTIONS_OPTIONS
            {0, 0, 0, 0}};
        longopts = optstruct;
        return chars;
    }
};
typedef main_optt<> main_opt;

} /// namespace archa
} /// namespace console
} /// namespace app
} /// namespace xos

#endif /// _XOS_APP_CONSOLE_ARCHA_MAIN_OPT_HPP 
