namespace :db do
  desc "To execute: rake RAILS_ENV=development db:load_customers"
  desc "Puts default customers in the database"
  task :load_parts => :environment do
    Part.create :pname=>"Nut", :color=>"Red", :weight=>12 , :city=>"London"
    Part.create :pname=>"Bolt", :color=>"Green", :weight=>17 , :city=>"Paris"
    Part.create :pname=>"Screw", :weight=>17, :city=>"Rome"
    Part.create :pname=>"Screw", :color=>"Red", :weight=>14, :city=>"London"
    Part.create :pname=>"Cam", :color=>"Blue", :weight=>12, :city=>"Paris"
    Part.create :pname=>"Cog", :color=>"Red", :weight=>19, :city=>"London"
  end
end