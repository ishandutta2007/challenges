#!/usr/bin/env ruby

class Hacker
	def initialize()
	end
end

class Submission
	def initialize()
	end
end

class TestCase
	def initialize()
	end
end

class Contest
	def initialize()
	end
end

def typeof(obj)
	case obj
	when Hacker
		puts "It's a Hacker!"
	when Submission
		puts "It's a Submission!"
	when TestCase
		puts "It's a TestCase!"
	when Contest
		puts "It's a Contest!"
	else
		puts "It's an unknown model"
	end
end

typeof(Hacker.new())
typeof(Submission.new())
typeof(TestCase.new())
typeof(Contest.new())
typeof(String.new())
