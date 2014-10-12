require "rspec/core/rake_task"
require "bundler/gem_tasks"
require "rake/extensiontask"

RSpec::Core::RakeTask.new :spec do |task|
  task.rspec_opts = ["--color"]
end

gem_spec = Gem::Specification.load('stmd-ruby.gemspec')
Rake::ExtensionTask.new('stmd_ruby', gem_spec)

task default: :spec
