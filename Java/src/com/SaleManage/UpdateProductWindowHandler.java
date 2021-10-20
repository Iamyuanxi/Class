package com.SaleManage;

import com.SaleManage.Entity.ProductInformation;
import com.SaleManage.Services.ProductService;
import com.SaleManage.Services.ProductServiceImpl;

import javax.swing.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class UpdateProductWindowHandler implements ActionListener {
    private UpdateProductWindow updateProductWindow;
    private ProductManageWindow productManageWindow;

    public UpdateProductWindowHandler(UpdateProductWindow updateProductWindow, ProductManageWindow productManageWindow) {
        this.updateProductWindow = updateProductWindow;
        this.productManageWindow = productManageWindow;
    }

    @Override
    public void actionPerformed(ActionEvent e) {
        JButton jButton = (JButton) e.getSource();
        String text = jButton.getText();

        if ("修改".equals(text)) {
            ProductService productService = new ProductServiceImpl();
            ProductInformation productInformation = updateProductWindow.buildUpdateProduct();
            boolean updateResult = productService.update(productInformation);

            if (updateResult) {
                //重新加载表格查到最新数据
                productManageWindow.reloadTable();
                updateProductWindow.dispose();
            } else {
                JOptionPane.showMessageDialog(updateProductWindow,"修改失败");
            }
        }
    }
}
