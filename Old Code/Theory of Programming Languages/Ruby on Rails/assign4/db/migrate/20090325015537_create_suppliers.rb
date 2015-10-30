class CreateSuppliers < ActiveRecord::Migration
  def self.up
    create_table :suppliers, :force=>true do |t|
      t.string :sname, :unique=>true, :null=>false
      t.integer :status
      t.string :city, :default=>"", :null=>false

      t.timestamps
    end
    add_index :suppliers, :sname, :unique=>true, :null=>false
    add_index :suppliers, :city, :null=>false
  end

  def self.down
    drop_table :suppliers
  end
end
