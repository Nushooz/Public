class ShipmentsController < ApplicationController
  before_filter :login_required
#  before_filter :login_required, :only => [ :edit, :update, :create, :new, :destroy ]
  # GET /shipments
  # GET /shipments.xml
 
  def index
    @shipments = Shipment.find(:all)

    respond_to do |format|
      format.html # index.html.erb
      format.xml  { render :xml => @shipments }
    end
  end

  # GET /shipments/1
  # GET /shipments/1.xml
  def show
    @shipment = Shipment.find(params[:id])

    respond_to do |format|
      format.html # show.html.erb
      format.xml  { render :xml => @shipment }
    end
  end

  # GET /shipments/new
  # GET /shipments/new.xml
  def new
    @shipment = Shipment.new

    respond_to do |format|
      format.html # new.html.erb
      format.xml  { render :xml => @shipment }
    end
  end

  # GET /shipments/1/edit
  def edit
    @shipment = Shipment.find(params[:id])
  end

  # POST /shipments
  # POST /shipments.xml
  
  def supplier_logged_in?(supplier_id)
    temp = Supplier.find_by_id(supplier_id)
#    pp current_user.id
    temp.user_id == current_user.id
  end
  
  def create
    @shipment = Shipment.new(params[:shipment])
    if supplier_logged_in?(@shipment.supplier_id)
     respond_to do |format|
        if @shipment.save 
          flash[:notice] = 'Shipment was successfully created.'
          format.html { redirect_to(@shipment) }
          format.xml  { render :xml => @shipment, :status => :created, :location => @shipment }
        else
          format.html { render :action => "new" }
          format.xml  { render :xml => @shipment.errors, :status => :unprocessable_entity }
        end
      end
     else
          flash[:notice] = 'You cannot create a shipment for someone other than yourself.'
     end
  end

 # def is_supplier_logged_in?
 #       @user = User.find(params[:supplier_id])
 #       @user.id == current_user.id
 # end
  
  # PUT /shipments/1
  # PUT /shipments/1.xml
  def update
    @shipment = Shipment.find(params[:id])

    respond_to do |format|
      if @shipment.update_attributes(params[:shipment])
        flash[:notice] = 'Shipment was successfully updated.'
        format.html { redirect_to(@shipment) }
        format.xml  { head :ok }
      else
        format.html { render :action => "edit" }
        format.xml  { render :xml => @shipment.errors, :status => :unprocessable_entity }
      end
    end
  end

  # DELETE /shipments/1
  # DELETE /shipments/1.xml
  def destroy
    @shipment = Shipment.find(params[:id])
    @shipment.destroy

    respond_to do |format|
      format.html { redirect_to(shipments_url) }
      format.xml  { head :ok }
    end
  end
end
