# coding: utf-8
lib = File.expand_path('../lib', __FILE__)
$LOAD_PATH.unshift(lib) unless $LOAD_PATH.include?(lib)
require 'stmd_ruby/version'

Gem::Specification.new do |spec|
  spec.name          = "stmd-ruby"
  spec.version       = Stmd::Ruby::VERSION
  spec.authors       = ["Joe Jackson"]
  spec.email         = ["cpmhjoe@gmail.com"]
  spec.summary       = %q{Wraps The STMD Markdown Library}
  spec.description   = %q{Using STMD (which intends to be the Markdown cannonical standard) to give access to html,
                          and directly to the Markdown AST }
  spec.homepage      = ""
  spec.license       = "MIT"

  spec.files         = `git ls-files -z`.split("\x0")
  spec.extensions    = ["ext/stmd_ruby/extconf.rb"]
  spec.executables   = spec.files.grep(%r{^bin/}) { |f| File.basename(f) }
  spec.test_files    = spec.files.grep(%r{^(test|spec|features)/})
  spec.require_paths = ["lib"]

  spec.add_development_dependency "bundler", "~> 1.7"
  spec.add_development_dependency "rake", "~> 10.0"
  spec.add_development_dependency "rake-compiler"
  spec.add_development_dependency "rspec", "~> 3.1"
end
