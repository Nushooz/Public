class CreateParts < ActiveRecord::Migration
  def self.up
    create_table :parts, :force=>true do |t|
      t.string :pname, :null=>false
      t.string :color, :default =>""
      t.integer :weight, :default=>0, :null=>false
      t.string :city, :null=>false

      t.timestamps
    end
    add_index :parts, :pname, :null=>false
    add_index :parts, :city, :null=>false
  end

  def self.down
    drop_table :parts
  end
end
