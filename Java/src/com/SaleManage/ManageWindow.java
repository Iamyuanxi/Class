package com.SaleManage;

import javax.swing.*;
import java.awt.*;

public class ManageWindow extends JFrame {
    JPanel northPanel = new JPanel(new FlowLayout(FlowLayout.LEFT));
    JButton addButton = new JButton("添加");
    JButton updateButton = new JButton("修改");
    JButton deleteButton = new JButton("删除");
    JTextField searchText = new JTextField(15);
    JButton searchButton = new JButton("查询");

    JPanel southPanel = new JPanel(new FlowLayout(FlowLayout.RIGHT));
    JButton preButton = new JButton("上一页");
    JButton nextButton = new JButton("下一页");

    ProductWindowTable windowTable = new ProductWindowTable();
    //ProductManageWindowHandler productManageWindowHandler;


    public ManageWindow(String title) {
        super(title);
        Container contentPane = getContentPane();
        //productManageWindowHandler = new ProductManageWindowHandler(this);
        //放置北边组件
        layoutNorth(contentPane);
        //放置中间的jTable
        //layoutCenter(contentPane);
        //放置南边组件
        layoutSouth(contentPane);

        setSize(1000,800);
        setLocationRelativeTo(null);
        setDefaultCloseOperation(DISPOSE_ON_CLOSE);
        setResizable(false);
        setVisible(true);
    }
    /*
    private void layoutCenter(Container contentPane) {
        TableDTO dto = getTableDTO();
        ProductWindowTableModel productWindowTableModel = ProductWindowTableModel.assembleModel(dto.getData());
        //把jTable和model关联
        windowTable.setModel(productWindowTableModel);
        windowTable.renderRule();

        JScrollPane jScrollPane = new JScrollPane(windowTable);

        contentPane.add(jScrollPane,BorderLayout.CENTER);
    }
    */

    private void layoutSouth(Container contentPane) {
        southPanel.add(preButton);
        southPanel.add(nextButton);
        contentPane.add(southPanel, BorderLayout.SOUTH);
    }

    private void layoutNorth(Container contentPane) {
        //增加事件监听
        //addButton.addActionListener(productManageWindowHandler);

        northPanel.add(addButton);
        northPanel.add(updateButton);
        northPanel.add(deleteButton);
        northPanel.add(searchText);
        northPanel.add(searchButton);
        contentPane.add(northPanel, BorderLayout.NORTH);
    }
    /*
    private TableDTO getTableDTO() {
        ProductService productService = new ProductServiceImpl();
        ProductRequest request = new ProductRequest();

        request.setSearchKey(searchText.getText().trim());

        TableDTO tableDTO = productService.retrieveProducts(request);

        return tableDTO;
    }

     */
    /*
    public void reloadTable() {
        TableDTO dto = getTableDTO();

        ProductWindowTableModel.updateModel(dto.getData());

        windowTable.renderRule();
    }
    */
}

