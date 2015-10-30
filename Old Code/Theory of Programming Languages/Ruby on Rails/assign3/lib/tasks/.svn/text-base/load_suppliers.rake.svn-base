namespace :db do
  desc "To execute: rake RAILS_ENV=development db:load_customers"
  desc "Puts default customers in the database"
  task :load_suppliers => :environment do
    Supplier.create :sname=>"Smith", :status=>20, :city=>"London"
    Supplier.create :sname=>"Jones", :status=>10, :city=>"Paris"
    Supplier.create :sname=>"Blake", :status=>30, :city=>"Paris"
    Supplier.create :sname=>"Clark", :status=>20, :city=>"London"
    Supplier.create :sname=>"Adams", :status=>30 #, :city=>
  end
end