require 'pp'

module SuppliersHelper
  def supplier_logged_in?(supplier_id)
    temp = Supplier.find_by_id(supplier_id)
#    pp current_user.id
    temp.user_id == current_user.id
  end
end
