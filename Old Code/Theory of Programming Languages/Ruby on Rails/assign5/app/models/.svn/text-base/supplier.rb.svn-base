class Supplier < ActiveRecord::Base
  belongs_to :user
  validates_format_of :status, :with => /^\d{2}$/
end
