class Supplier < ActiveRecord::Base
  validates_format_of :status, :with => /^\d{2}$/
end
