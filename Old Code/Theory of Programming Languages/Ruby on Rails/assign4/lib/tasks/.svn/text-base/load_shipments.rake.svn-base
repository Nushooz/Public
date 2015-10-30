namespace :db do
  desc "To execute: rake RAILS_ENV=development db:load_customers"
  desc "Puts default customers in the database"
  task :load_shipments => :environment do
    Shipment.create :supplier_id=>1, :part_id=>1, :qty=>300, :price=>0.005
    Shipment.create :supplier_id=>1, :part_id=>2, :qty=>200, :price=>0.009
    Shipment.create :supplier_id=>1, :part_id=>3, :qty=>400, :price=>0.004
    Shipment.create :supplier_id=>1, :part_id=>4, :qty=>200, :price=>0.009
    Shipment.create :supplier_id=>1, :part_id=>5, :qty=>100, :price=>0.01
    Shipment.create :supplier_id=>1, :part_id=>6, :qty=>100, :price=>0.01
    Shipment.create :supplier_id=>2, :part_id=>1, :qty=>400, :price=>0.006
    Shipment.create :supplier_id=>2, :part_id=>2, :qty=>300, :price=>0.004
    Shipment.create :supplier_id=>3, :part_id=>2, :qty=>400, :price=>0.009
    Shipment.create :supplier_id=>3, :part_id=>3, :qty=>200
    Shipment.create :supplier_id=>4, :part_id=>2, :qty=>300, :price=>0.005
    Shipment.create :supplier_id=>4, :part_id=>3, :price=>0.005
    Shipment.create :supplier_id=>4, :part_id=>4, :qty=>300, :price=>0.006
    Shipment.create :supplier_id=>4, :part_id=>5, :qty=>400, :price=>0.003
  end
end