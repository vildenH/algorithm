select distinct g.*,sv.spec_value from es_goods g, es_tag_rel r, es_member m, es_goods_spec gs, es_spec_values sv where g.store_id = m.store_id and m.state = 1 and g.goods_type = 'normal' and g.disabled=0 and g.market_enable=1 and g.audit_flag=2 and g.goods_id=r.rel_id  and g.goods_id = gs.goods_id  and sv.spec_value_id = gs.spec_value_id and gs.spec_id != 8 and  g.cat_id in(select c.cat_id from es_goods_cat  c where c.cat_path like '0|1|%') AND r.tag_id=4 order by r.ordernum desc