class Shipment < ActiveRecord::Base
  belongs_to :supplier
  belongs_to :part
  validates_presence_of :supplier_id
  validates_presence_of :supplier
  validates_presence_of :part_id
  validates_presence_of :part
end
