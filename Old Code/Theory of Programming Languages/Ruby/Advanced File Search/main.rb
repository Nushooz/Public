#Programmer: Mark Kaiser
#Assignment 2
#Due Date:2/05/09
#Insrutctor: Dr. Al Cripps
#This program takes in a command line argument that is a regular expression and 
#searches the folders and files within the program for matches against the regular
#expression. When all the matches are found, they are displayed as output.
# The following regular expressions were tested
#.*[m]+.*
#.*[mM]+.*
#.*[nN]$
#.*[xX][mM][lL]$
#.*[sS][vV][nN]$
#^[pP][rR][oO][jJ][eE][cC][tT].*      # The program does not work with /^project.*/i as Regex.new automatically tags
#.*[pP][rR][oO][jJ][eE][cC][tT].*     # the string with / / and the additional i cannot be added as a string.

homedir = Dir.pwd.to_s        # Setup the home directory of the assignment
homedir.gsub!(/\/[^\/]+$/,'') # Magic!
@matches ||= []

Dir.chdir(homedir)            # Change the base level of program
filearray = Dir.entries(homedir)  # Create an array full of all files within homedir
filearray.reject! {|e| e == "." || e == ".."} # Remove . and .., they are not real directories

def searchin(directory) #Searches the given directory for a match against ARGV[0]
    Dir.chdir(directory) #Enter the directory
    currdir = Dir.pwd.to_s  # Set currdir as the current directory
    filearray = Dir.entries(currdir)  # Update filearray with current directory files
    filearray.reject! {|e| e == "." || e == ".."} # Remove . and .., they are not real directories
    filearray.each do |file|  # For each file in the directory
      currfile = currdir + "/" + file.to_s  # Set the file to the current file
      if (FileTest.directory?(currfile))    # If that file is a directory
        reg = Regexp.new(ARGV[0])
        if (file.match(reg) != nil)         # Compare it to the regular expression, add it if it matches
          @matches += (currdir + "/" + file.to_s).to_a 
        end
        searchin(currdir + "/" + file.to_s) # Then search in the directory
      else
        reg = Regexp.new(ARGV[0])
        if (file.match(reg) != nil)         # Compare it to the regular expression, add it if it matches
          @matches += (currdir + "/" + file.to_s).to_a   
        end
      end
    end
end

searchin(homedir)       # Search from the home directory outward
if (@matches.size == 0) # If there are no matches
  puts "Sorry, no matches were found!"
else
  puts "The following matches were found:"
  @matches.each do |match|      # Output the matches
    puts match.to_s
  end
end

