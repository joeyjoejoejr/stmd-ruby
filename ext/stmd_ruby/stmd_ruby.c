#include "ruby.h"

VALUE mStmdRuby;

static VALUE t_md_to_html(VALUE rb_self, VALUE rb_md_input) {
  return rb_str_new2("h1");
}

void Init_stmd_ruby() {
  VALUE mStmdRuby = rb_define_module("StmdRuby");
  rb_define_singleton_method(mStmdRuby, "md_to_html", t_md_to_html, 1);
}
