#include "ruby.h"
#include "stmd.h"

VALUE mStmdRuby;
VALUE cNode;

static VALUE t_md_to_html(VALUE rb_self, VALUE rb_md_input) {
  strbuf html = GH_BUF_INIT;
  VALUE return_html;
  node_block *document;

  char *md_input_cstr = RSTRING_PTR(rb_md_input);
  int md_input_length = RSTRING_LEN(rb_md_input);

  document = stmd_parse_document(md_input_cstr, md_input_length);
  stmd_render_html(&html, document);
  return_html = rb_str_new(html.ptr, html.size);

  stmd_free_nodes(document);
  strbuf_free(&html);

  return return_html;
}

static VALUE t_md_to_ast(VALUE rb_self, VALUE rb_md_input) {
  VALUE argv[0];
  VALUE cNode_instance = rb_class_new_instance(0, argv, cNode);
  return cNode_instance;
}

void Init_stmd_ruby() {
  mStmdRuby = rb_define_module("StmdRuby");
  cNode = rb_define_class_under(mStmdRuby, "Node", rb_cObject);
  rb_define_singleton_method(mStmdRuby, "md_to_html", t_md_to_html, 1);
  rb_define_singleton_method(mStmdRuby, "md_to_ast", t_md_to_ast, 1);
}
