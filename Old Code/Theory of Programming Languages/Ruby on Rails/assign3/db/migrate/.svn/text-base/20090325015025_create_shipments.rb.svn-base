class CreateShipments < ActiveRecord::Migration
  def self.up
    create_table :shipments, :force=>true do |t|
      t.integer :supplier_id, :unique=>true, :null=>false
      t.integer :part_id, :unique=>true, :null=>false
      t.integer :qty, :default =>0, :null=>false
      t.decimal :price, :default =>0, :null=>false, :precision=>15, :scale=>3

      t.timestamps
    end
  end

  def self.down
    drop_table :shipments
  end
end
