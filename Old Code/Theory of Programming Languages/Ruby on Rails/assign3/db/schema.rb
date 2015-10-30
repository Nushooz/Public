# This file is auto-generated from the current state of the database. Instead of editing this file, 
# please use the migrations feature of Active Record to incrementally modify your database, and
# then regenerate this schema definition.
#
# Note that this schema.rb definition is the authoritative source for your database schema. If you need
# to create the application database on another system, you should be using db:schema:load, not running
# all the migrations from scratch. The latter is a flawed and unsustainable approach (the more migrations
# you'll amass, the slower it'll run and the greater likelihood for issues).
#
# It's strongly recommended to check this file into your version control system.

ActiveRecord::Schema.define(:version => 20090325034829) do

  create_table "parts", :force => true do |t|
    t.string   "pname",      :default => "", :null => false
    t.string   "color",      :default => ""
    t.integer  "weight",     :default => 0,  :null => false
    t.string   "city",       :default => "", :null => false
    t.datetime "created_at"
    t.datetime "updated_at"
  end

  add_index "parts", ["city"], :name => "index_parts_on_city"
  add_index "parts", ["pname"], :name => "index_parts_on_pname"

  create_table "shipments", :force => true do |t|
    t.integer  "supplier_id",                                                 :null => false
    t.integer  "part_id",                                                     :null => false
    t.integer  "qty",                                        :default => 0,   :null => false
    t.decimal  "price",       :precision => 15, :scale => 3, :default => 0.0, :null => false
    t.datetime "created_at"
    t.datetime "updated_at"
  end

  create_table "suppliers", :force => true do |t|
    t.string   "sname",      :default => "", :null => false
    t.integer  "status"
    t.string   "city",       :default => "", :null => false
    t.datetime "created_at"
    t.datetime "updated_at"
  end

  add_index "suppliers", ["city"], :name => "index_suppliers_on_city"
  add_index "suppliers", ["sname"], :name => "index_suppliers_on_sname", :unique => true

end