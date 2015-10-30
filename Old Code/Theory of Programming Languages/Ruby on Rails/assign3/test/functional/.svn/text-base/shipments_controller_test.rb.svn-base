require 'test_helper'

class ShipmentsControllerTest < ActionController::TestCase
  test "should get index" do
    get :index
    assert_response :success
    assert_not_nil assigns(:shipments)
  end

  test "should get new" do
    get :new
    assert_response :success
  end

  test "should create shipment" do
    assert_difference('Shipment.count') do
      post :create, :shipment => { }
    end

    assert_redirected_to shipment_path(assigns(:shipment))
  end

  test "should show shipment" do
    get :show, :id => shipments(:one).id
    assert_response :success
  end

  test "should get edit" do
    get :edit, :id => shipments(:one).id
    assert_response :success
  end

  test "should update shipment" do
    put :update, :id => shipments(:one).id, :shipment => { }
    assert_redirected_to shipment_path(assigns(:shipment))
  end

  test "should destroy shipment" do
    assert_difference('Shipment.count', -1) do
      delete :destroy, :id => shipments(:one).id
    end

    assert_redirected_to shipments_path
  end
end
