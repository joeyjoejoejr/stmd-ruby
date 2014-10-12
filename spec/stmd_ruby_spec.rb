require 'spec_helper'

describe StmdRuby do
  describe "::md_to_html" do
    it "generates html from markdown" do
      html = StmdRuby::md_to_html <<MARKDOWN
# Header 1
MARKDOWN
      expect(html).to match /h1/
    end
  end
end
