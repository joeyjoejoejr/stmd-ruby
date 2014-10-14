require 'spec_helper'

describe StmdRuby do
  describe "::md_to_html" do
    it "generates html from markdown" do
      html = StmdRuby::md_to_html <<MARKDOWN
# Header 1
## Header 2
### Header 3

* foo
* bar
* baz `foo` _monkey_
MARKDOWN
      expect(html).to match /h1/
      expect(html).to match /h2/
      expect(html).to match /h3/
      expect(html).to match /ul/
      expect(html).to match /li/
      expect(html).to match /code/
      expect(html).to match /em/
    end

    it "passes the specs" do
      File.read("spec/spec.txt").scan(/TESTSTART.*?MIDDLE.*?TESTEND/m).each do |test|
        markdown = test[/.*MIDDLE/m].gsub(/TESTSTART|MIDDLE/, '').gsub("→", "\t")
        expected_parsed = test[/MIDDLE.*/m].gsub(/TESTEND|MIDDLE/, '')

        expected_stripped = expected_parsed.gsub /\s+/, ''
        result_stripped = StmdRuby::md_to_html(markdown).gsub /\s+/, ''
        expect(result_stripped).to eq expected_stripped
      end
    end

    describe "::md_to_ast" do
      it "returns an ast" do
        ast = StmdRuby::md_to_ast <<MARKDOWN
# Header 1
## Header 2
### Header 3

* foo
* bar
* baz `foo` _monkey_
MARKDOWN
        expect(ast).to be_kind_of(StmdRuby::Node)
      end
    end
  end
end
