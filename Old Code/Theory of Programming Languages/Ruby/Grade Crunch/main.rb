#Programmer: Mark Kaiser
#Assignment 1
#Due Date:1/29/09
#Insrutctor: Dr. Al Cripps
#The purpose of this program is to evaluate a series of students and their respective
#grades. The program uses a .csv file to read in relevent student information, and
#it removes entries with invalid grades and email addresses. Once all the records
#have been entered, it finds the mean, median, minimum grade, maximum grade, and
#standard deviation. The program also returns the number of total grades as well as
#the student who achieved the highest and lowest grade. The program also prints
#a horizontal bargraph to graphicaly display the distribution of the grades. After
#the program has evaluated a record file, the user is prompted for another file or
#or allows the user to quit the program.


require 'pp'
require 'csv'

$stdout.sync = true     #remove buffered output

class Grades            # Class to hold student information and grade evaluation methods
  attr_reader :grades
  Struct.new("User",:last,:first, :account, :password, :email, :score )

  def initialize        # This is the constructor for the class.
    @grades ||=  []     # Define a new array
  end

  def error_in(line)    #Checks for the correct size of input and checks the score to be a valid score and valid email address
      line.size != 6 or line[5].match(/^\s*[+-]?[0-9]+\s*$/)==nil or line[5].to_i > 100 or line[5].to_i < 0 or line[4].match('\b[a-zA-Z0-9._-]+@[a-zA-Z0-9.]+\b')==nil
  end

  def fileopen?
    return @grades.size
  end

  def maximum   # Return the maximum grade
    max = 0
    @grades.each do |instance|
      if max < instance.score.to_i
        max = instance.score.to_i
      end
    end
    return max
  end

  def maxachiever    # Returns the person who had the highest grade, I could
    max = 0          # probably do this within maximum but this works for now
    maxperson = ""
    @grades.each do |instance|
      if max < instance.score.to_i
        max = instance.score.to_i
        maxperson = instance.first + " " + instance.last
      end
    end
    return maxperson
  end

  def minimum    # Returns the minimum grade
    min = 999
    @grades.each do |instance|
      if min > instance.score.to_i
        min = instance.score.to_i
      end
    end
    return min
  end

  def minachiever   # Returns the person with the lowest grade
    min = 999
    minperson = ""
    @grades.each do |instance|
      if min > instance.score.to_i
        min = instance.score.to_i
        minperson = instance.first + " " + instance.last
      end
    end
    return minperson
  end

  def average     # Returns the average grade for a class
    sum = 0
    numscores = @grades.size
    @grades.each do |instance|
       sum += instance.score.to_i
    end
    average = sum.to_f / numscores
    return average
  end

  def median      # Returns the median grade
    array ||= []
    @grades.each do |instance|
      array += [instance.score]
    end
    array.sort! # Sort the array, even though its already sorted

    evenorodd = array.size % 2
    index = array.size / 2
    if evenorodd == 0
      median = (array[index-1].to_f + array[index].to_f) / 2
      return median
    else
      median = array[index]
      return median
    end
  end

  def standard   # Returns the standard deviation of a number of grades
    sum = 0
    sumsquared = 0
    n = @grades.size
    @grades.each do |instance|
       sum += instance.score.to_i
       sumsquared += instance.score.to_f**2
    end
    dev = Math.sqrt( (n*(sumsquared) - (sum.to_f**2)) / (n*(n-1)) )
    return dev
  end

  def numscores     # need yield here
    yield @grades.size if block_given?
  end

  def drawgraph     # Draws a horizontal bar graph to show grade distribution
    array = Array.new(101, 0) # Create a frequency array initialized to zero

    index = 0
    @grades.each do |instance| # Increment the array for every score in grades
        index = instance.score.to_i
        array[index] +=  1
    end

    100.downto(0) do |n|   # Print score graph starting at 100 to 0
      print n.to_s + " "
      count = array[n].to_i
      for k in 1..count do   # Prints a % for each grade within the freqeuncy array
        print "%"            # Each % represents a single grade
      end
      print "\n"
    end
    print "\n"
  end

  def read_in(filename)
       CSV.open(filename, 'r') do |row|
            yield row if block_given?
            @grades << Struct::User.new(row[0],row[1],row[2],row[3],row[4],row[5]) unless error_in row
       end
  end

end

puts 'Welcome to the Grade Crunching Program!' #prompt user for filename
print 'Please enter a filename: '

while ( (filename = gets) != "\n" ) do
  if filename.match('\b[a-zA-Z0-9._%+-]+\.csv$') != nil  #Verify the datafile is a .csv file
    obj = Grades.new
    obj.read_in(filename.strip!) # {|value| pp value} # for debugging
    if (obj.fileopen? > 0 )
      obj.grades.sort! {|a,b|a.score <=> b.score}
      obj.drawgraph
      puts "The highest score is " + obj.maximum.to_s + " and was made by " + obj.maxachiever
      puts "The lowest score is " + obj.minimum.to_s + " and was made by " + obj.minachiever
      print "The average score is "
      printf("%.1f\n", obj.average)
      puts "The median score is " + obj.median.to_s
      print "The standard deviation is "
      printf("%.2f\n", obj.standard)
      obj.numscores {|value| puts "The number of scores is " + value.to_s}
      puts 'File processed!'
      else
        puts "This file either does not exist or is corrupt, no file was processed."
    end
  else
    puts 'This file could not be read, please make sure your datafile is a .csv file'
  end
    print 'Please enter another filename(or hit enter to quit): '
end

puts 'Exiting Program...Thanks Again!'